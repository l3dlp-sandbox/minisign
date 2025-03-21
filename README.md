![CodeQL scan](https://github.com/jedisct1/minisign/workflows/CodeQL%20scan/badge.svg)

# Minisign

Minisign is a dead simple tool to sign files and verify signatures.

For more information, please refer to the
[Minisign documentation](https://jedisct1.github.io/minisign/)

Tarballs and pre-compiled binaries can be verified with the following
public key:

    RWQf6LRCGA9i53mlYecO4IzT51TGPpvWucNSCh1CBM0QTaLn73Y7GFO3

## Compilation / installation

## Building with Zig

Dependencies:

- [libsodium](https://libsodium.org/) (_optional_)
- [zig](https://ziglang.org)

Compilation with libsodium, dynamically linked (libsodium will need to be installed on the system for the command to run):

    $ zig build -Doptimize=ReleaseSmall

Compilation with libsodium, statically linked (libsodium will only be needed for compilation):

    $ zig build -Doptimize=ReleaseSmall -Dstatic

Compilation without libsodium, no dependencies required:

    $ zig build -Doptimize=ReleaseSmall -Dwithout-libsodium

The resulting binary can be found in `zig-out/bin/minisign`.

In all these examples, `ReleaseFast` can be replaced with `ReleaseSmall` to favor speed over size.

## Building with cmake and gcc or clang:

Dependencies:

- [libsodium](https://libsodium.org/) (_required_)
- cmake
- pkg-config
- gcc or clang

Compilation:

    $ mkdir build
    $ cd build
    $ cmake ..
    $ make
    # make install

Alternative configuration for static binaries:

    $ cmake -D STATIC_LIBSODIUM=1 ..

or:

    $ cmake -D BUILD_STATIC_EXECUTABLES=1 ..

## Pre-built packages

Minisign is also available in Homebrew:

    $ brew install minisign

Minisign is also available in Scoop on Windows:

    $ scoop install minisign

Minisign is also available in chocolatey on Windows:

    $ choco install minisign

Minisign is also available with docker:

    $ docker run -i --rm jedisct1/minisign

For example, verifying a signature using the docker image can be done
with:

    $ docker run -v .:/minisign -e HOME=/minisign -w /minisign \
      -it --rm jedisct1/minisign \
      -Vm file_to_verify -p minisign.pub

The image can be verified with the following cosign public key:

```text
-----BEGIN PUBLIC KEY-----
MFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAExjZWrlc6c58W7ZzmQnx6mugty99C
OQTDtJeciX9LF9hEbs1J1fzZHRdRhV4OTqcq0jTW9PXnrSSZlk1fbkE/5w==
-----END PUBLIC KEY-----
```

## Additional tools, libraries and implementations

- [minizign](https://github.com/jedisct1/zig-minisign) is a compact
  implementation in Zig, that can also use ssh-encoded keys.
- [minisign-misc](https://github.com/JayBrown/minisign-misc) is a very
  nice set of workflows and scripts for macOS to verify and sign files
  with minisign.
- [go-minisign](https://github.com/jedisct1/go-minisign) is a small module
  in Go to verify Minisign signatures.
- [rust-minisign](https://github.com/jedisct1/rust-minisign) is a Minisign
  library written in pure Rust, that can be embedded in other applications.
- [rsign2](https://github.com/jedisct1/rsign2) is a reimplementation of
  the command-line tool in Rust.
- [minisign (go)](https://github.com/aead/minisign) is a rewrite of Minisign
  in the Go language. It reimplements the CLI but can also be used as a library.
- [minisign-verify](https://github.com/jedisct1/rust-minisign-verify) is
  a small Rust crate to verify Minisign signatures.
- [minisign-net](https://github.com/bitbeans/minisign-net) is a .NET library
  to handle and create Minisign signatures.
- [minisign](https://github.com/chm-diederichs/minisign) a Javascript
  implementation.
- WebAssembly implementations of [rsign2](https://wapm.io/package/jedisct1/rsign2)
  and [minisign-cli](https://wapm.io/package/jedisct1/minisign) are available on
  WAPM.
- [minisign-php](https://github.com/soatok/minisign-php) is a PHP implementation.
- [py-minisign](https://github.com/x13a/py-minisign) is a Python
  implementation.
- [minisign](https://hexdocs.pm/minisign/Minisign.html) is an Elixir implementation
  (verification only)

## Signature determinism

This implementation uses deterministic signatures, unless libsodium
was compiled with the `ED25519_NONDETERMINISTIC` macro defined. This
adds random noise to the computation of EdDSA nonces.

Other implementations can choose to use non-deterministic signatures
by default. They will remain fully interoperable with implementations
using deterministic signatures.
