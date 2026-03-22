import os
from pygments import highlight
from pygments.lexers import CLexer
from pygments.formatters import ImageFormatter

def generate_screenshot(file_path, output_path, start_line, end_line, title):
    with open(file_path, 'r', encoding='utf-8') as f:
        lines = f.readlines()
    
    code = ''.join(lines[start_line-1:end_line])
    
    formatter = ImageFormatter(
        font_name="Consolas",
        font_size=18,
        line_numbers=True,
        style="monokai",
        title=title,
        line_pad=8
    )
    
    with open(output_path, 'wb') as f:
        f.write(highlight(code, CLexer(), formatter))

if __name__ == "__main__":
    generate_screenshot(
        r"c:\Users\facundo\Desktop\University_Projects\C_Multiple_Purpose_Functions_Libraries\Libraries\Networking\sock_lib.c",
        r"c:\Users\facundo\Desktop\University_Projects\C_Multiple_Purpose_Functions_Libraries\Screenshot_Networking.png",
        13, 63,
        "Network TCP Client Connection (C_Multiple_Purpose_Functions_Libraries/Libraries/Networking/sock_lib.c)"
    )
    generate_screenshot(
        r"c:\Users\facundo\Desktop\University_Projects\C_Multiple_Purpose_Functions_Libraries\Libraries\LinkedLists\singly_linked.c",
        r"c:\Users\facundo\Desktop\University_Projects\C_Multiple_Purpose_Functions_Libraries\Screenshot_LinkedLists.png",
        153, 176,
        "Singly Linked List Node Insertion (C_Multiple_Purpose_Functions_Libraries/Libraries/LinkedLists/singly_linked.c)"
    )
    generate_screenshot(
        r"c:\Users\facundo\Desktop\University_Projects\C_Multiple_Purpose_Functions_Libraries\Libraries\Sorting\my_sorting.c",
        r"c:\Users\facundo\Desktop\University_Projects\C_Multiple_Purpose_Functions_Libraries\Screenshot_Sorting.png",
        22, 77,
        "Optimized Bubble Sort Algorithm (Libraries/Sorting/my_sorting.c)"
    )
    generate_screenshot(
        r"c:\Users\facundo\Desktop\University_Projects\C_Multiple_Purpose_Functions_Libraries\Libraries\Encryption\string_encrypt.c",
        r"c:\Users\facundo\Desktop\University_Projects\C_Multiple_Purpose_Functions_Libraries\Screenshot_Encryption.png",
        22, 68,
        "String Encryption with Caesar Shift (Libraries/Encryption/string_encrypt.c)"
    )
    generate_screenshot(
        r"c:\Users\facundo\Desktop\University_Projects\C_Multiple_Purpose_Functions_Libraries\Libraries\Matrix\matrix_ops.c",
        r"c:\Users\facundo\Desktop\University_Projects\C_Multiple_Purpose_Functions_Libraries\Screenshot_Matrix_Mult.png",
        592, 626,
        "Dynamic Matrix Multiplication (Libraries/Matrix/matrix_ops.c)"
    )
    generate_screenshot(
        r"c:\Users\facundo\Desktop\University_Projects\C_Multiple_Purpose_Functions_Libraries\Libraries\Strings\my_strings.c",
        r"c:\Users\facundo\Desktop\University_Projects\C_Multiple_Purpose_Functions_Libraries\Screenshot_String_Concat.png",
        110, 158,
        "Dynamic String Concatenation (Libraries/Strings/my_strings.c)"
    )
    generate_screenshot(
        r"c:\Users\facundo\Desktop\University_Projects\C_Multiple_Purpose_Functions_Libraries\Libraries\FileIO\bin_file_rw.c",
        r"c:\Users\facundo\Desktop\University_Projects\C_Multiple_Purpose_Functions_Libraries\Screenshot_BinaryFileIO.png",
        32, 79,
        "Structs Array to Binary File Write (Libraries/FileIO/bin_file_rw.c)"
    )
    generate_screenshot(
        r"c:\Users\facundo\Desktop\University_Projects\C_Multiple_Purpose_Functions_Libraries\Libraries\Strings\my_strings.c",
        r"c:\Users\facundo\Desktop\University_Projects\C_Multiple_Purpose_Functions_Libraries\Screenshot_String_Sort.png",
        303, 351,
        "Selection Sort of Strings Array (Libraries/Strings/my_strings.c)"
    )
    generate_screenshot(
        r"c:\Users\facundo\Desktop\University_Projects\C_Multiple_Purpose_Functions_Libraries\Libraries\Bitwise\bit_ops.c",
        r"c:\Users\facundo\Desktop\University_Projects\C_Multiple_Purpose_Functions_Libraries\Screenshot_Bitwise.png",
        53, 84,
        "Bitwise Operations: SetBit (Libraries/Bitwise/bit_ops.c)"
    )
    generate_screenshot(
        r"c:\Users\facundo\Desktop\University_Projects\C_Multiple_Purpose_Functions_Libraries\Libraries\LinkedLists\doubly_linked.c",
        r"c:\Users\facundo\Desktop\University_Projects\C_Multiple_Purpose_Functions_Libraries\Screenshot_DoublyLinkedList.png",
        159, 191,
        "Doubly Linked List Traversal (Libraries/LinkedLists/doubly_linked.c)"
    )
    print("Screenshots generated!")
