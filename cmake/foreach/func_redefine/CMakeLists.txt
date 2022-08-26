message("-------------------")
function(TEST)
    message("TEST1")
    message("TEST1")
    message("TEST1")
    message("TEST1")
    message("TEST1")
endfunction()

TEST()

message("-------------------")
function(test)
    message("TEST2")
    message("TEST2")
    message("TEST2")
    message("TEST2")
    message("TEST2")
endfunction()

TEST()

message("-------------------")
include("test.cmake")

TEst()