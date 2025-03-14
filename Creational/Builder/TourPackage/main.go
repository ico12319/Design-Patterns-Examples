package main

import (
	"TourPackage/builders"
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {

	fmt.Println("Enter a desired tour package: ")
	fmt.Println("Type luxury or adventure!")
	reader := bufio.NewReader(os.Stdin)
	typeBuilder, _ := reader.ReadString('\n')
	typeBuilder = strings.TrimSpace(typeBuilder)
	builder := builders.CreateBuilder(typeBuilder)

	director := builders.NewDirector(builder)
	tourPackage := director.BuildTourPackage()
	tourPackage.ShowInfo()

}
