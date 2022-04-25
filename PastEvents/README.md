# PastEvents (Event 3)

`PastEvents` is raised, and only sent to the room master upon join. It lets the room master that we would like to initialize a synchronization of past events.

The room master will proceed to respond to this request with [SyncEvents (Event 4)](../SyncEvents/README.md), and [SyncFinished (Event 5)](../SyncFinished/README.md) events.

This event has no custom data.