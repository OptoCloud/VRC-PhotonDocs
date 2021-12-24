fn getUSpeakPacketCount() {
    u128 totalSize = std::mem::size();
    u128 pos = $;
    u128 packets = 0;
    while (pos < totalSize) {
        pos = pos + std::mem::read_unsigned(pos + 2, 2) + 4;
        packets = packets + 1;
    }
    return packets;
};
bitfield OpusTOC {
/*
   +-----------------------+-----------+-----------+-------------------+
   | Configuration         | Mode      | Bandwidth | Frame Sizes       |
   | Number(s)             |           |           |                   |
   +-----------------------+-----------+-----------+-------------------+
   | 0...3                 | SILK-only | NB        | 10, 20, 40, 60 ms |
   |                       |           |           |                   |
   | 4...7                 | SILK-only | MB        | 10, 20, 40, 60 ms |
   |                       |           |           |                   |
   | 8...11                | SILK-only | WB        | 10, 20, 40, 60 ms |
   |                       |           |           |                   |
   | 12...13               | Hybrid    | SWB       | 10, 20 ms         |
   |                       |           |           |                   |
   | 14...15               | Hybrid    | FB        | 10, 20 ms         |
   |                       |           |           |                   |
   | 16...19               | CELT-only | NB        | 2.5, 5, 10, 20 ms |
   |                       |           |           |                   |
   | 20...23               | CELT-only | WB        | 2.5, 5, 10, 20 ms |
   |                       |           |           |                   |
   | 24...27               | CELT-only | SWB       | 2.5, 5, 10, 20 ms |
   |                       |           |           |                   |
   | 28...31               | CELT-only | FB        | 2.5, 5, 10, 20 ms |
   +-----------------------+-----------+-----------+-------------------+
*/
    config : 5;
    
/*
    0 indicates mono and 1 indicates stereo.
*/
    isStereo : 1;
    
/*
   0: 1 frame in the packet
   1: 2 frames in the packet, each with equal compressed size
   2: 2 frames in the packet, with different compressed sizes
   3: an arbitrary number of frames in the packet
*/
    frames : 2;
};
struct OpusPacket {
    OpusTOC toc;
    u8 frameData[parent.size - 1];
};
struct USpeakPacket {
    u16 index;
    u16 size;
    OpusPacket opus;
};
struct USpeakHeader {
    s32    senderActorNr;
    s32    serverTicks;
    USpeakPacket packets[getUSpeakPacketCount()]; // normally 2-3 packets
};
USpeakHeader packet @ 0x00;
