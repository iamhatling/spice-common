/* -*- Mode: C; c-basic-offset: 4; indent-tabs-mode: nil -*- */
/*
   Copyright (C) 2013 Jeremy White <jwhite@codeweavers.com>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, see <http://www.gnu.org/licenses/>.
*/

#ifndef H_SPICE_COMMON_SND_CODEC
#define H_SPICE_COMMON_SND_CODEC

#define SND_CODEC_OPUS_FRAME_SIZE       480
#define SND_CODEC_OPUS_PLAYBACK_FREQ    48000
#define SND_CODEC_OPUS_COMPRESSED_FRAME_BYTES 480

#define SND_CODEC_PLAYBACK_CHAN         2

#define SND_CODEC_MAX_FRAME_SIZE        SND_CODEC_OPUS_FRAME_SIZE
#define SND_CODEC_MAX_FRAME_BYTES       (SND_CODEC_MAX_FRAME_SIZE * SND_CODEC_PLAYBACK_CHAN * 2 /* FMT_S16 */)
#define SND_CODEC_MAX_COMPRESSED_BYTES  SND_CODEC_OPUS_COMPRESSED_FRAME_BYTES

#define SND_CODEC_ANY_FREQUENCY        -1

#define SND_CODEC_OK                    0
#define SND_CODEC_UNAVAILABLE           1
#define SND_CODEC_ENCODER_UNAVAILABLE   2
#define SND_CODEC_DECODER_UNAVAILABLE   3
#define SND_CODEC_ENCODE_FAILED         4
#define SND_CODEC_DECODE_FAILED         5
#define SND_CODEC_INVALID_ENCODE_SIZE   6

#define SND_CODEC_ENCODE                0x0001
#define SND_CODEC_DECODE                0x0002

SPICE_BEGIN_DECLS

typedef struct SndCodecInternal * SndCodec;

int  snd_codec_is_capable(int mode, int frequency);

int  snd_codec_create(SndCodec *codec, int mode, int frequency, int purpose);
void snd_codec_destroy(SndCodec *codec);

int  snd_codec_frame_size(SndCodec codec);

int  snd_codec_encode(SndCodec codec, uint8_t *in_ptr, int in_size, uint8_t *out_ptr, int *out_size);
int  snd_codec_decode(SndCodec codec, uint8_t *in_ptr, int in_size, uint8_t *out_ptr, int *out_size);

SPICE_END_DECLS

#endif
