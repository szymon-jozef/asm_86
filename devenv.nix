{
  pkgs,
  lib,
  config,
  inputs,
  ...
}:
let
  clang = lib.getExe' pkgs.pkgsi686Linux.clang "clang";
  clangpp = lib.getExe' pkgs.pkgsi686Linux.clang "clang++";
in
{
  env = {
    CMAKE_C_COMPILER = clang;
    CMAKE_CXX_COMPILER = clangpp;
  };

  enterShell =
    # bash
    ''
      export CC="${clang}";
      export CXX="${clangpp}";
    '';

  packages = with pkgs; [
    cmake
    gnumake
    clangMultiStdenv.cc
    pkgsi686Linux.clang-tools
    gdb
    cgdb
  ];
}
