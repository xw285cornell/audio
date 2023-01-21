#pragma once

#include <torchaudio/csrc/ffmpeg/ffmpeg.h>
#include <iostream>

namespace torchaudio {
namespace ffmpeg {

struct SrcStreamInfo {
  /// @name COMMON MEMBERS
  ///@{

  ///
  /// The stream media type.
  ///
  /// Please see refer to
  /// [the FFmpeg
  /// documentation](https://ffmpeg.org/doxygen/4.1/group__lavu__misc.html#ga9a84bba4713dfced21a1a56163be1f48)
  /// for the available values
  ///
  /// @todo Introduce own enum and get rid of FFmpeg dependency
  ///
  AVMediaType media_type;
  /// The name of codec.
  const char* codec_name = "N/A";
  /// The name of codec in long, human friendly form.
  const char* codec_long_name = "N/A";
  /// For audio, it is sample format.
  ///
  /// Commonly found values are;
  /// - ``"u8"``, ``"u8p"``: 8-bit unsigned integer.
  /// - ``"s16"``, ``"s16p"``: 16-bit signed integer.
  /// - ``"s32"``, ``"s32p"``: 32-bit signed integer.
  /// - ``"s64"``, ``"s64p"``: 64-bit signed integer.
  /// - ``"flt"``, ``"fltp"``: 32-bit floating point.
  /// - ``"dbl"``, ``"dblp"``: 64-bit floating point.
  ///
  /// For video, it is color channel format.
  ///
  /// Commonly found values include;
  /// - ``"gray8"``: grayscale
  /// - ``"rgb24"``: RGB
  /// - ``"bgr24"``: BGR
  /// - ``"yuv420p"``: YUV420p
  const char* fmt_name = "N/A";

  /// Bit rate
  int64_t bit_rate = 0;

  /// Number of frames.
  /// @note In some formats, the value is not reliable or unavailable.
  int64_t num_frames = 0;

  /// Bits per sample
  int bits_per_sample = 0;

  /// Metadata
  ///
  /// This method can fetch ID3 tag from MP3.
  ///
  /// Example:
  ///
  /// ```
  /// {
  ///   "title": "foo",
  ///   "artist": "bar",
  ///   "date": "2017"
  /// }
  /// ```
  OptionDict metadata{};

  ///@}

  /// @name AUDIO-SPECIFIC MEMBERS
  ///@{

  /// Sample rate
  double sample_rate = 0;

  /// The number of channels
  int num_channels = 0;

  ///@}

  /// @name VIDEO-SPECIFIC MEMBERS
  ///@{

  /// Width
  int width = 0;

  /// Height
  int height = 0;

  /// Frame rate
  double frame_rate = 0;
  ///@}
};

struct OutputStreamInfo {
  /// The index of the input source stream
  int source_index;
  /// Filter graph definition, such as
  /// ``"aresample=16000,aformat=sample_fmts=fltp"``.
  std::string filter_description;
};

} // namespace ffmpeg
} // namespace torchaudio
