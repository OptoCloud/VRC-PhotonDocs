# RatelimitValueSync (Event 34)

Used to configure the built-in rate-limiter in the client. It is only sent by the Photon server.

This event's data is a dictionary of `byte`, `int`; The dictionary's key is the event code, while the value is the allowed rate per second.
```go
map[byte]int{
 	1: 60,   // uSpeak
 	3: 5,    // RequestPastEvents
 	4: 200,  // InitialSync
 	5: 50,   // FinalizeInitialSync
 	6: 400,  // VRCEvent
 	7: 500,  // UnreliableSerialization
 	8: 1,    // InterestManagement
 	9: 75,   // ReliableSerialization
 	33: 2,   // ExecutiveAction
 	40: 1,   // SetActorPropsPartial
 	42: 1,   // SetActorPropsPartial2
	60: 1,   // PhysBonesPermissions
 	202: 1,  // Instantiate
 	209: 20, // RequestOwnership
    210: 90, // TakeOwnership
}
```