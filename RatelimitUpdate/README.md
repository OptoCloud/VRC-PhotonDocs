# RatelimitUpdate (Event 35)

Used to let the built-in rate-limiter in the client know which actors are rate-limited. It is sent only by the server, and the tick rate is once per second.

Currently, this seems to have no effect, and the actors list in the custom data is always empty.

#### Format
If the update tick has no rate-limited actors, the custom data in the event is `null`, otherwise, it's a `[]int`