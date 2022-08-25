set(mylist "a" "b" c "d")
foreach(_var ${mylist})
	message("当前变量是：${_var}")
endforeach()
