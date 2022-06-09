git clone https://github.com/AMReX-Codes/amrex.git
cp Make.local amrex/Tools/GNUMake
cd amrex
./configure --prefix=.
make -j
make install

