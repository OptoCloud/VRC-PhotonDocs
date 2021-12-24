Table of Contents: 
```toc
    style: bullet | number (default: bullet)
    min_depth: number (default: 2)
    max_depth: number (default: 6)
```
---

### Event Codes

| Code | Event Name              | Description                                       | Authoritative                            | DocLink                                                                |
| ---- | ----------------------- | ------------------------------------------------- | ---------------------------------------- | ---------------------------------------------------------------------- |
| `0`  | `Unused`                | Unused event.                                     | No.                                      | N/A                                                                    |
| `1`  | `VoiceDataReceived`     | uSpeak.                                           | No.                                      | N/A                                                                    |
| `2`  | `ExecutiveMessage`      | Used by backend to communicate alerts to clients. | Yes.                                     | N/A                                                                    |
| `3`  | `SendPastEvents`        | Used to request the past events of an instance.   | No. (Make sure it's only sent to Master) | N/A                                                                    |
| `4`  | `SyncEvents`            | Used as a response to SendPastEvents              | No.                                      | N/A                                                                    |
| `5`  | `InitialSyncFinished`   | Marks a SendPastEvents request as finished.       | No.                                      | N/A                                                                    |
| `6`  | `ProcessEvent`          | Broadcast Used for RPCs.                          | No.<sup>1</sup>                          | N/A                                                                    |
| `7`  | `Serialization`         | Used for IK data serialization.                   | No.                                      | N/A                                                                    |
| `8`  | `ReceiveInterval`       | Used for interest list sync.                      | Yes.                                     | [[#ReceiveInterestPacket]], [[#InterestRecord]]                        |
| `9`  | `ReliableSerialization` | Used for AV3 & Udon sync.                         | No.                                      | N/A                                                                    |
| `15` | `BigData` / `ChairSync` | Not known.                                        | ??                                       | N/A                                                                    |
| `33` | `ExecutiveAction`       | General Moderation event.                         | Yes.                                     | [[#ModNetworkProperty Event 33 - ExecutiveAction\|ModNetworkProperty]] |
| `34` | `RatelimitValues`       | In-game rate-limiter                              | Yes.                                     | N/A                                                                    |
| `35` | ???                     | ???                                               | Yes.                                     | N/A                                                                    |
| `40` | `UserRecordUpdate`      | Used to update a user's details.                  | Yes.                                     | [[#RecordUpdateFlags]]                                                 |
|      |                         |                                                   |                                          |                                                                        |


1: *Would be nice to have partial authoritative validation in the "anti-monkey" version.*
2: Good-to-have; Disallow Master-only ReceiverGroup on 202 (Instantiate).

---


### ModNetworkProperty (Event 33 - ExecutiveAction)

| Code | Description     | Notes                                                                                                                       |
| ---- | --------------- | --------------------------------------------------------------------------------------------------------------------------- |
| `0`  | `Type`          | Seems to be one of [[#ModNetworkEvent]]                                                                                     |
| `1`  | `Target_User`   | Photon ActorId of the target user. Globals are unknown, but likely 0.                                                       |
| `2`  | `Message`       | N/A  (Possibly the message to show for actions that would pop up an alert box?)                                             |
| `3`  | `Main_Property` | Likely used as a placeholder value for custom data (e.g.: Photon ActorId to teleport `Target` to when `Type` is `Teleport`) |
| `5`  | `Heading`       | Header when `Type` is `Alert`.                                                                                              |
| `6`  | `Location_Data` | Used when `Type` is `Teleport_User`.                                                                                        | 
| `8`  | `World_Id`      | Likely used when `Type` is `Warp_To_Instance`                                                                               |
| `9`  | `Instance_id`   | Likely used when `Type` is `Warp_To_Instance`                                                                               |
| `10` | `Blocked_Users` | Still figuring this one out.                                                                                                |
| `11` | `Muted_Users`   | Still figuring this one out.                                                                                                |

Note: `Blocked_Users` and `Muted_Users` can be either `bool` or `Int32` (Photon ActorId), possibly depending on whether `Target_User` is set and the `Type` of the event.


---


### ModNetworkEvent
These are the available `Type`s for ModNetworkProperty


| Code (byte) | Description          | Notes                                                                                          |
| ----------- | -------------------- | ---------------------------------------------------------------------------------------------- |
| `1`         | `Enforce_Moderation` | Likely used to immediately enforce a pending moderation.                                       |
| `2`         | `Alert`              | N/A                                                                                            |
| `3`         | `Warn`               | N/A                                                                                            |
| `4`         | `Kick`               | N/A                                                                                            |
| `5`         | `Vote_Kick`          | N/A                                                                                            |
| `6`         | `Public_Ban`         | N/A                                                                                            |
| `7`         | `Ban`                | N/A                                                                                            |
| `8`         | `Mic_Off`            | Disables the microphone of the target user.                                                    |
| `9`         | `Mic_Volume_Adjust`  | N/A                                                                                            |
| `10`        | `Friend_Change`      | N/A (Likely used to broadcast a friendship change [e.g.: AddFriend, DeleteFriend]?)            |
| `11`        | `Warp_To_Instance`   | Likely related to the "Warp to Instance" feature available in the DevTools menu in the new UI. |
| `12`        | `Teleport_User`      | N/A                                                                                            |
| `13`        | `Query`              | N/A                                                                                            |
| `20`        | `Request_PlayerMods` | N/A                                                                                            |
| `21`        | `Reply_PlayerMods`   | N/A                                                                                            |
| `22`        | `Block_User`         | N/A                                                                                            |
| `23`        | `Mute_User`          | N/A                                                                                            |


---

### RecordUpdateFlags
These are the flags assigned to Event 40 (`UserRecordUpdate`)

| Code  | Description            |
| ----- | ---------------------- |
| `0x1` | `Avatar`               | 
| `0x2` | `Fallback_Avatar`      |
| `4`   | `User_Icon`            |
| `8`   | `Status`               |
| `16`  | `Allow_Avatar_Copying` |
| `32`  | `Profile_Picture`      |
| `64`  | `Bio`                  |


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
