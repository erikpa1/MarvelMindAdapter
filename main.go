package main

import "C"
import (
	"fmt"
	"strings"
)

//export ProcessString
func ProcessString(input *C.char) {
	// Convert C string to Go string
	goString := C.GoString(input)

	// Logic: Split the comma-separated string
	parts := strings.Split(goString, ",")

	fmt.Printf("[Go DLL] Received %d elements:\n", len(parts))
	for i, part := range parts {
		fmt.Printf("  %d: %s\n", i+1, strings.TrimSpace(part))
	}
}

func main() {
	// We need an empty main for the DLL to compile
}
