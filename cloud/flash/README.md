# FLASH 4.8 cloud environment

Target: Ubuntu 24.04 x86_64 with GNU compilers, OpenMPI, parallel HDF5, HYPRE, BLAS and LAPACK.

## Environment installation

Run from the repository root during environment setup (network and root/passwordless sudo required):

```bash
bash cloud/flash/install.sh
```

The script checks platform and dependencies. It does not establish that FLASH builds or that a simulation succeeds.

## Provide FLASH separately

This public repository contains environment configuration only. Provide your authorized FLASH 4.8 source and input data separately in the cloud workspace. Do not commit proprietary source, material tables or simulation output to this public repository.

Set FLASH_ROOT to the extracted source directory. Install the site configuration:

```bash
export FLASH_ROOT=/workspace/FLASH4.8
mkdir -p "$FLASH_ROOT/sites/cloud-ubuntu24"
cp cloud/flash/Makefile.h "$FLASH_ROOT/sites/cloud-ubuntu24/Makefile.h"
cd "$FLASH_ROOT"
./setup -auto magnetoHD/ZPinch -1d +cylindrical +ug species=fill,line,vacu +mtmmmt +usm3t +mgd mgd_meshgroups=6 +hdf5typeio -site=cloud-ubuntu24 -objdir=object-cloud
make -C object-cloud -j2
```

This reproduces the local setup options. Use a new build directory rather than uploaded local binaries. The source must include the user's ZPinch modifications.

## Runtime validation

Before launching flash4, supply the intended flash.par and every referenced EOS, opacity and circuit input file in an isolated run directory. Do not assume default parameters reproduce the user's simulation. Begin with a bounded, low-resolution test and a small number of MPI ranks; verify normal termination, HDF5 output with h5dump, and checkpoint restart before longer runs. Do not start a full simulation automatically.

Cloud installation, compilation, execution, and checkpoint validation must each be reported separately. Publishing repository files is not publishing a prepared Codex environment; run setup and review its results in the environment editor before publishing.
