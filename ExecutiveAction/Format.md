# ModNetworkProperty (Event 33 - ExecutiveAction)

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
