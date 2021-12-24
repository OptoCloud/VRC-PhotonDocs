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
