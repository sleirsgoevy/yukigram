{
  description = "Yukigram";
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  outputs = { self, nixpkgs }: rec {
    packages = builtins.mapAttrs (system: pkgs: rec {
      yukigram = pkgs.callPackage ./default.nix {};
      default = yukigram;
    }) nixpkgs.legacyPackages;
  };
}
