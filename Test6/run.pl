#!/usr/bin/perl
#Comprehensive tests of .o files 

system "../instrResolve foo.o bar.o > instructor.out";
system "../resolve foo.o bar.o > student.out";
system "diff -b instructor.out student.out > diffs";
if (! system "test -s diffs")
{
    print "Failed: ../resolve foo.o bar.o\n";
} else
{
    print "Passed: ../resolve foo.o bar.o\n";
}
system "rm -f instructor.out student.out diffs";

