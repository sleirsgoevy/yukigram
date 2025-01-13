{ lib, tdesktop }:

tdesktop.override {
  unwrapped = tdesktop.unwrapped.overrideAttrs (f: {
    name = "yukigram";
    src = ./.;
  });
}
