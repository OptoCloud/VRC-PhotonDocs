Table of Contents: 
```toc
    style: bullet | number (default: bullet)
    min_depth: number (default: 2)
    max_depth: number (default: 6)
```
---

### Event Codes

| Code  | Event Name                 | Description                                       | Authoritative                            | DocLink                                                                |
| ----- | -------------------------- | ------------------------------------------------- | ---------------------------------------- | ---------------------------------------------------------------------- |
| `1`   | `Voice`                    | uSpeak.                                           | No.                                      | [format](uSpeak/Format.md)                                             |
| `2`   | `ExecutiveMessage`         | Used by backend to communicate alerts to clients. | Yes.                                     | [format](ExecutiveMessage/Format.md)                                   |
| `3`   | `PastEvents`               | Used to request the past events of an instance.   | No. (Make sure it's only sent to Master) | N/A                                                                    |
| `4`   | `SyncEvents`               | Used as a response to SendPastEvents              | No.                                      | N/A                                                                    |
| `5`   | `SyncFinished`             | Marks a SendPastEvents request as finished.       | No.                                      | N/A                                                                    |
| `6`   | `ProcessEvent`             | Broadcast Used for RPCs.                          | No.                                      | N/A                                                                    |
| `7`   | `Unreliable Serialization` | Used for IK data serialization.                   | No.                                      | N/A                                                                    |
| `8`   | `InterestManagement`       | Used for interest list sync.                      | Yes.                                     | [[#ReceiveInterestPacket]], [[#InterestRecord]]                        |
| `9`   | `Relaible Serialization`   | Used for AV3 & Udon sync.                         | No.                                      | N/A                                                                    |
| `15`  | `BigData` / `ChairSync`    | Not known.                                        | ??                                       | N/A                                                                    |
| `33`  | `ExecutiveAction`          | General Moderation event.                         | Yes.                                     | [[#ModNetworkProperty Event 33 - ExecutiveAction\|ModNetworkProperty]] |
| `34`  | `RatelimitValues`          | In-game rate-limiter                              | Yes.                                     | N/A                                                                    |
| `35`  | ???                        | ???                                               | Yes.                                     | N/A                                                                    |
| `40`  | `UserRecordUpdate`         | Used to update a user's details.                  | Yes.                                     | [[#RecordUpdateFlags]]                                                 |
| `202` | `Instanciate`              |                                                   |                                          |                                                                        |
| `209` | `OwnershipRequest`         |                                                   |                                          |                                                                        |
| `210` | `OwnershipTransfer`        |                                                   |                                          |                                                                        |
| `211` | `VacantViewIds`            |                                                   |                                          |                                                                        |
| `223` | `Auth`                     |                                                   |                                          |                                                                        |
| `226` | `Stats`                    |                                                   |                                          |                                                                        |
| `230` | `Authenticate`             |                                                   |                                          |                                                                        |
| `252` | `SetProperties`            |                                                   |                                          |                                                                        |
| `253` | `PropertiesChanged`        |                                                   |                                          |                                                                        |
| `254` | `Leave`                    |                                                   |                                          |                                                                        |
| `255` | `Join`                     |                                                   |                                          |                                                                        |

---

### ReceiveInterestPacket
The custom data on the **received** interest packet (EvCode 8) is an `int[]` of actor numbers that can _receive_ ___our___ events. This is based on the function name `CanHearMe(int remote)`, which probes `InterestManager.instance.listeners` to check whether `remote` is in the listeners.

### InterestRecord
Event 8 **sent** from the client.

Each player we're interested in (excluding ourselves) has twelve (12) bytes assigned.

```cs
var bytePos = 0;
var evt8Structure = new byte[loadBalancingClient.CurrentRoom.Players.Values.Count * 12 - 12]; // 12 bytes per player + excluding our own

foreach (var player in loadBalancingClient.CurrentRoom.Players.Values)
{
    if (player.ActorNumber == loadBalancingClient.LocalPlayer.ActorNumber)
        continue;

    Array.Copy( // viewId (ActorNr + 00001)
        BitConverter.GetBytes(int.Parse(player.ActorNumber + "00001")), // byte[] of ActorNr + 00001
        0, // Source index; Copy from start of byte[]
        evt8Structure, // Copy to evt8Structure
        bytePos, // Copy to pos.
        4 // Bytes to copy.
    );

    bytePos += 4; // Add 4 to the bytePos (we added 4 bytes to the structure)
    evt8Structure[bytePos++] = 0; // updateFrequency
    evt8Structure[bytePos++] = 255; // voiceQuality

    Array.Copy( // viewId (ActorNr + 00003)
        BitConverter.GetBytes(int.Parse(player.ActorNumber + "00003")), // byte[] of ActorNr + 00003
        0, // Source index; Copy from start of byte[]
        evt8Structure, // Copy to evt8Structure
        bytePos, // Copy to pos.
        4 // Bytes to copy.
    );

    bytePos += 4; // Add 4 to the bytesPos (we added 4 bytes to the structure)
    evt8Structure[bytePos++] = 0; // updateFrequency
    evt8Structure[bytePos++] = 0; // voiceQuality (ALWAYS 0 for 00003)
}
```
<!-- TODO: Clean this up later.
| Type                          | Description       | Offset |
| ----------------------------- | ----------------- | ------ |
| `int`                         | `viewId`          | `0x10` |
| `byte`                        | `updateFrequency` | `0x14` |
| `FlatBufferNetworkSerializer` | `serializer`      | `0x18` |
| `byte`                        | `voiceQuality`    | `0x20` |
-->
