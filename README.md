# PhotonDocs

This is a repository to share documentation about the photon protocol that VRChat uses.

## Tools (feel free to add yours)

[ImHex](https://github.com/WerWolv/ImHex) will be used to document a bunch of the binary formats here and is a really neat reverse engineering tool to have

[PhotonDebug](https://github.com/OptoCloud/PhotonDebug) Is a photon debug tool made by HentaiHeaven#0001 and logs all photon data to json log files.

## Events

| Code  | Event Name                 | Description                                       | Authoritative             | Docs                                                                            |
| ----- | -------------------------- | ------------------------------------------------- | ------------------------- | ------------------------------------------- |
| `1`   | `Voice`                    | uSpeak.                                           | No.                       | [format](Voice/README.md)                   |
| `2`   | `ExecutiveMessage`         | Used by backend to communicate alerts to clients. | Yes.                      | [format](ExecutiveMessage/README.md)        |
| `3`   | `PastEvents`               | Used to request the past events of an instance.   | No. (Only send to Master) | [format](PastEvents/README.md)              |
| `4`   | `SyncEvents`               | Used as a response to SendPastEvents              | No.                       | [format](SyncEvents/README.md)              |
| `5`   | `SyncFinished`             | Marks a SendPastEvents request as finished.       | No.                       | [format](SyncFinished/README.md)            |
| `6`   | `ProcessEvent`             | Broadcast Used for RPCs.                          | No.                       | [format](ProcessEvent/README.md)            |
| `7`   | `Unreliable Serialization` | Used for IK data serialization.                   | No.                       | [format](ReliableSerialization/README.md)   |
| `8`   | `InterestManagement`       | Used for interest list sync.                      | Yes.                      | [format](InterestManagement/README.md)      |
| `9`   | `Relaible Serialization`   | Used for AV3 & Udon sync.                         | No.                       | [format](UnreliableSerialization/README.md) |
| `33`  | `ExecutiveAction`          | General Moderation event.                         | Yes.                      | [format](ExecutiveAction/README.md)         |
| `34`  | `RatelimitValueSync`       | In-game rate-limiter                              | Yes.                      | [format](RatelimitValueSync/README.md)      |
| `35`  | `RatelimitUpdate`          | Update Tick for Ratelimited Actors                | Yes.                      | [format](RatelimitUpdate/README.md)         |
| `40`  | `UserRecordUpdate`         | Used to update a user's details.                  | Yes.                      | [format](UserRecordUpdate/README.md)        |
| `202` | `Instantiate`              |                                                   |                           |                                             |
| `209` | `OwnershipRequest`         |                                                   |                           |                                             |
| `210` | `OwnershipTransfer`        |                                                   |                           |                                             |
| `211` | `VacantViewIds`            |                                                   |                           |                                             |
| `223` | `Auth`                     |                                                   |                           |                                             |
| `226` | `Stats`                    |                                                   |                           |                                             |
| `230` | `Authenticate`             |                                                   |                           |                                             |
| `252` | `SetProperties`            |                                                   |                           |                                             |
| `253` | `PropertiesChanged`        |                                                   |                           |                                             |
| `254` | `Leave`                    |                                                   |                           |                                             |
| `255` | `Join`                     |                                                   |                           |                                             |
