# Events

| Code  | Event Name                 | Description                                       | Authoritative                            | DocLink                                                                |
| ----- | -------------------------- | ------------------------------------------------- | ---------------------------------------- | ---------------------------------------------------------------------- |
| `1`   | `Voice`                    | uSpeak.                                           | No.                                      | [format](Voice/README.md)                                             |
| `2`   | `ExecutiveMessage`         | Used by backend to communicate alerts to clients. | Yes.                                     | [format](ExecutiveMessage/README.md)                                   |
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
