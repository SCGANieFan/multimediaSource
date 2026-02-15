
//opus
opusCodec.exe -e audio 48000 2 30000 mbz_48k2h.pcm mbz_48k2h.pcm.opus
opusCodec.exe -d 48000 1 mbz_48k2h.pcm.opus mbz_48k2h.pcm.opus.pcm
opusCodec.exe voip 8000 1 6000 ./man_track_8k_1ch.pcm ./man_track_8k_1ch.pcm.opus6500.pcm

opusCodec.exe voip 8000 1 6000 -cbr -framesize 10 -complexity 0 ./man_track_8k_1ch.pcm ./man_track_8k_1ch.pcm.opus6000.pcm

//silk
SilkEncode.exe man_track_8k_1ch.pcm man_track_8k_1ch.silk -Fs_API 8000 -rate 8000
SilkDecode.exe man_track_8k_1ch.silk man_track_8k_1ch.silk.pcm -Fs_API 8000


//lc3
lc3p.exe -bps 16 -bandwidth 20000 -frame_ms 10 -q ./in.wav ./in.wav.lc3bd20kpbs64k10ms.wav 64000


//ape
//enc
// -c1000 -c2000   -c3000  -c4000      -c5000
// fast    normal  high    extra high  insane
ape.exe "in.wav" "in.wav.ape" -c2000
//dec
ape.exe "in.wav.ape" "in.wav.ape.wav" -d

ape.exe "mbz_48k2h.wav" "mbz_48k2h.wav.ape" -c2000
ape.exe "mbz_48k2h.wav.ape" "mbz_48k2h.wav.ape.wav" -d


ape.exe "Inuyasha_48k2ch.wav" "Inuyasha_48k2ch.wav.ape" -c2000
ape.exe "Inuyasha_48k2ch.wav.ape" "Inuyasha_48k2ch.wav.ape.wav" -d




