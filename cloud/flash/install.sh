#!/usr/bin/env bash
set -euo pipefail

# Run during cloud environment setup, with package-manager network access.
source /etc/os-release
if [[ "$ID" != ubuntu || "$VERSION_ID" != 24.04 || "$(uname -m)" != x86_64 ]]; then
  echo 'This configuration requires Ubuntu 24.04 x86_64.' >&2
  exit 1
fi
priv=()
if (( EUID != 0 )); then
  sudo -n true
  priv=(sudo -n)
fi
"${priv[@]}" apt-get update
"${priv[@]}" env DEBIAN_FRONTEND=noninteractive apt-get install -y \
  build-essential gfortran python3 git pkg-config \
  openmpi-bin libopenmpi-dev libhdf5-openmpi-dev hdf5-tools \
  libhypre-dev libblas-dev liblapack-dev zlib1g-dev libaec-dev \
  libssl-dev libcurl4-openssl-dev

for tool in mpif90.openmpi mpicc.openmpi mpicxx.openmpi h5pcc h5dump; do
  command -v "$tool"
done
h5pcc -showconfig | grep -E 'HDF5 Version|Parallel HDF5'
h5pcc -showconfig | grep -Eq 'Parallel HDF5: *yes'
test -f /usr/include/hypre/HYPRE.h
test -f /usr/lib/x86_64-linux-gnu/libHYPRE.so
echo 'Dependencies installed. FLASH compilation and simulation validation are still required.'
