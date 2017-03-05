// compile: zig build main.zig --name main --export exe

const io = @import("std").io;

fn check_equal(comptime T : type, expected : T, actual : T) -> void {
    
    if( expected != actual ) {
        %%io.stdout.printf("Check equal: values are not equal.\n");
        %%io.stdout.printf("Expected: {}\n", expected);
        %%io.stdout.printf("Actual: {}\n", actual);        
    }
}


fn add(comptime T : type, a : T, b : T) -> T {
    return a+b;
}


pub fn main(args : [][]u8) -> %void{
    comptime var T_Int : type = i32;
    
    check_equal(T_Int, add(T_Int, 1, 2), 3);
    check_equal(T_Int, add(T_Int, 1, 2), 4);
}
