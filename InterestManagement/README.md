# InterestManagement (Event 8)

## Sent Packet
Informs the server of which PhotonView IDs the client is interested in. The encoding format can be found [[Event Codes/8/Format|here]].

```c
int32_t viewId; // The ViewID we're setting the interest of.
uint8_t byte_1; // Interest Setting 1 | Effects unknown
uint8_t byte_2; // Interest Setting 2 | Effects unknown
```

An `InterestManagement` event may contain more than one interest set.

## Received packet

Usually received on a one second interval, the custom data is an `int[]` of actor ids that we are receiving events from.
