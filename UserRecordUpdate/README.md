# UserRecordUpdate (Event 40)

## RecordUpdateFlags

Raised upon making an API request that would alter the user model (such as updating your `status`, `statusDescription`, `bio`, changing avatars).


Upon raising this event, the Photon server will broadcast a `SetActorProperties` event with the user's updated properties according to the API.


This event's data is a `short`, and follows this format:
| Code     | Description            |
| -------- | ---------------------- |
| `1 << 0` | `Avatar`               | 
| `1 << 1` | `Fallback_Avatar`      |
| `1 << 2` | `User_Icon`            |
| `1 << 3` | `Status`               |
| `1 << 4` | `Allow_Avatar_Copying` |
| `1 << 5` | `Profile_Picture`      |
| `1 << 6` | `Bio`                  |
