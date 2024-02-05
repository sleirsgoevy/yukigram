{ lib, tdesktop }:

tdesktop.overrideAttrs (f: {
  name = "yukigram";
  src = ./.;
  postFixup = builtins.concatStringsSep "$out/bin/yukigram" (lib.splitString "$out/bin/telegram-desktop" f.postFixup);
})
