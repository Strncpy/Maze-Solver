# Maze-Solver
 Computer programming project
 
# Authors
  - Man N. Darius
  - Păcuraru L. Fabian Virgil
  - Zah D. Elena
  
 # Description
   The projects aimes to generate a maze of a certain size and the user will try to solve the specific maze. He will have a score based  on how many mazes he solved

# Install graphis.h in CodeBlocks
   1. Copy "graphics.h" and "winbgim.h" into (instalation folder of CodeBlocks)CodeBlocks\MinGW\include
   2. Copy "libbgi.a" into (instalation folder of CodeBlocks)CodeBlocks\MinGW\lib
   3. In CodeBlocks, Settings->Compiler...->Global compiler settings->Linker settings.
      On the right in "Other linker options:" paste: -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32.
      On the left in "Link libraries" click Add and select from (instalation folder of CodeBlocks)CodeBlocks\MinGW\lib "libbgi.a"
   4. Click "OK"
