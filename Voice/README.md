# Voice (Event 1)

This event contains voice packets encoded in opus, with the USpeak packet format.

## Structure
```cs
struct USpeakPacket {
    uint16_t index; // Packet counter, increments with each uSpeak packet
    uint16_t size;  // amount of bytes of encoded opus data in this uSpeak packet
    uint8_t  opusData[this.size];
};
struct USpeakHeader {
    int32_t senderActorNr;  // Photon Id of sernder
    int32_t serverTicks;    // Server ticks at send time
    USpeakPacket packets[]; // normally 2-3 packets
};
```

## Opus encoding

| Setting    | Value    |
| ---------- | -------- |
| Band Mode  | `48 kHz` |
| Bitrate    | `24 kHz` |
| Opus Delay | `20 ms`  |
| Channels   | `Mono?`  |

## Examples
[USpeakNative](https://github.com/OptoCloud/USpeakNative) (Ask HentaiHeaven#0001 on discord for access if you cant access this repo)
