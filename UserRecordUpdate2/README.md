# UserRecordUpdate.. 2? (Event 42)

# Copied documentation from [information-redacted](https://github.com/information-redacted)

Behaves much like [UserRecordUpdate (Event 40)](../UserRecordUpdate/README.md). Once it's raised, the server broadcasts a `SetActorProperties` event with the updated user properties.


This event was added in build `1169` in preparation for the IK beta.


---


This event seems to be taking the place of operation 252 (SetProperties). It behaves exactly the same, but only send properties that have actually changed.

