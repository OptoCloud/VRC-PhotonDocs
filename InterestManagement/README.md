# InterestManagement (Event 8)

### ReceiveInterestPacket
The custom data on the **received** interest packet (EvCode 8) is an `int[]` of actor numbers that can _receive_ ___our___ events. This is based on the function name `CanHearMe(int remote)`, which probes `InterestManager.instance.listeners` to check whether `remote` is in the listeners.
