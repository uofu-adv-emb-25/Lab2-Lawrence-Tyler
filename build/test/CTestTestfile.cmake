# CMake generated Testfile for 
# Source directory: /home/lawrence/Documents/Repos/ECE5785/Labs/Lab2-Lawrence-Tyler/test
# Build directory: /home/lawrence/Documents/Repos/ECE5785/Labs/Lab2-Lawrence-Tyler/build/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(simulate_mytest "/usr/bin/renode" "--disable-xwt" "--port" "-2" "--pid-file" "renode.pid" "--console" "-e" "\$ELF=@/home/lawrence/Documents/Repos/ECE5785/Labs/Lab2-Lawrence-Tyler/build/test/mytest.elf; \$WORKING=@/home/lawrence/Documents/Repos/ECE5785/Labs/Lab2-Lawrence-Tyler; include @/home/lawrence/Documents/Repos/ECE5785/Labs/Lab2-Lawrence-Tyler/test/simulate.resc; start")
set_tests_properties(simulate_mytest PROPERTIES  _BACKTRACE_TRIPLES "/home/lawrence/Documents/Repos/ECE5785/Labs/Lab2-Lawrence-Tyler/test/CMakeLists.txt;39;add_test;/home/lawrence/Documents/Repos/ECE5785/Labs/Lab2-Lawrence-Tyler/test/CMakeLists.txt;0;")
