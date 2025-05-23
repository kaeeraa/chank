{
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";

  outputs =
    { self, nixpkgs }:
    let
      systems = [
        "x86_64-linux"
        "aarch64-linux"
        "aarch64-darwin"
      ];
      forAllSystems = nixpkgs.lib.genAttrs systems;
    in
    {
      devShells = forAllSystems (
        system:
        let
          pkgs = nixpkgs.legacyPackages.${system};
        in
        {
          default = pkgs.mkShell {
            nativeBuildInputs = [
              pkgs.cmake
              pkgs.ninja
              pkgs.kdePackages.qtbase
              pkgs.clang-tools
              pkgs.clang
              pkgs.apr
              pkgs.aprutil
              pkgs.mysql80
              pkgs.postgresql
              pkgs.apacheHttpd
            ];
            shellHook = ''
              mkdir -p build
              cd build
              cmake ..
            '';
          };
        }
      );
    };
}
