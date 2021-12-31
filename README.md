# PhotonDocs

This is a repository to share documentation about the photon protocol that VRChat uses.

## Tools (feel free to add yours)

[ImHex](https://github.com/WerWolv/ImHex) will be used to document a bunch of the binary formats here and is a really neat reverse engineering tool to have

[PhotonDebug](https://github.com/OptoCloud/PhotonDebug) Is a photon debug tool made by HentaiHeaven#0001 and logs all photon data to json log files.

## OpCodes

[Official documentation](https://doc-api.photonengine.com/en/pun/v1/class_operation_code.html)

### VRChat specific documentation for OpCodes: 

| Code  | OpCode Name                | Description | Docs                                        |
| ----- | -------------------------- | ----------- | ------------------------------------------- |
| `217` | `GetRoomList`              |             |                                             |
| `219` | `WebRPC`                   |             |                                             |
| `220` | `GetRegions`               |             |                                             |
| `221` | `GetLobbyStats`            |             |                                             |
| `222` | `FindFriends`              |             |                                             |
| `225` | `JoinRandomRoom`           |             |                                             |
| `226` | `JoinRoom`                 |             |                                             |
| `227` | `CreateRoom`               |             |                                             |
| `228` | `LeaveLobby`               |             |                                             |
| `229` | `JoinLobby`                |             |                                             |
| `230` | `Authenticate`             |             |                                             |
| `231` | `AuthenticateOnce`         |             |                                             |
| `251` | `GetProperties`            |             |                                             |
| `252` | `SetProperties`            |             |                                             |
| `253` | `RaiseEvent`               |             |                                             |
| `254` | `Leave`                    |             |                                             |
| `255` | `Join`                     |             |                                             |


## Events

These are events that can be sent by invoking Operation ``RaiseEvent`` (``253``)

| Code  | Event Name                 | Description                                       | Authoritative             | Docs                                                                            |
| ----- | -------------------------- | ------------------------------------------------- | ------------------------- | ------------------------------------------- |
| `1`   | `Voice`                    | Voice transmission via uSpeak.                    | No.                       | [format](Voice/README.md)                   |
| `2`   | `ExecutiveMessage`         | Used by backend to communicate alerts to clients. | Yes.                      | [format](ExecutiveMessage/README.md)        |
| `3`   | `PastEvents`               | Used to request the past events of an instance.   | No. (Only send to Master) | [format](PastEvents/README.md)              |
| `4`   | `SyncEvents`               | Used as a response to SendPastEvents              | No.                       | [format](SyncEvents/README.md)              |
| `5`   | `SyncFinished`             | Marks a SendPastEvents request as finished.       | No.                       | [format](SyncFinished/README.md)            |
| `6`   | `ProcessEvent`             | Broadcast Used for VrcEvents (like RPCs).         | No.                       | [format](ProcessEvent/README.md)            |
| `7`   | `Unreliable Serialization` | Used for any type of data that can be interpolated or doesn't have to be sent reliably.                  | No.                       | [format](ReliableSerialization/README.md)   |
| `8`   | `InterestManagement`       | Used for interest list sync.                      | Yes.                      | [format](InterestManagement/README.md)      |
| `9`   | `Reliable Serialization`   | Used for any type of data that should always be reliably sent like AV3 parameters, Udon Sync and late joiner position sync for players and pickups.                         | No.                       | [format](UnreliableSerialization/README.md) |
| `33`  | `ExecutiveAction`          | General Moderation event.                         | Yes.                      | [format](ExecutiveAction/README.md)         |
| `34`  | `RatelimitValueSync`       | In-game rate-limiter                              | Yes.                      | [format](RatelimitValueSync/README.md)      |
| `35`  | `RatelimitUpdate`          | Update Tick for Ratelimited Actors                | Yes.                      | [format](RatelimitUpdate/README.md)         |
| `40`  | `UserRecordUpdate`         | Used to update a user's details.                  | Yes.                      | [format](UserRecordUpdate/README.md)        |
| `202` | `Instantiate`              |                                                   |                           |                                             |
| `209` | `OwnershipRequest`         |                                                   |                           |                                             |
| `210` | `OwnershipTransfer`        |                                                   |                           |                                             |
| `211` | `VacantViewIds`            |                                                   |                           |                                             |
