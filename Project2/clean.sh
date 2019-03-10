#!/bin/sh
# Justin Baskaran
# CS 232- Project 2
# March 06, 2019
NumFiles=0

clean_files () {
#shopt -s dotglob
#DIR=$1/*
DIR=$(ls -a $1)
Inter=""
Quiet=""
Stats=""
for var in "$@"
do
    if test $var = "i"; then
        unset Inter
        Inter="i"  
    fi
    if test $var = "q" ; then
        unset Quiet
        Quiet="q" 
    fi

    if test $var = "s" ; then
        unset Stats
        Stats="s"

    fi
done
#echo "Directory Values: "$DIR
for file in $DIR; do
    if [ -d $1/$file ] && [ $file != '.' ] && [ $file != '..' ];
    then
        #echo "Directory "$1/$file
        clean_files $1/$file $Inter $Quiet $Stats $NumFiles
    elif [ $file != '.' ] && [ $file != '..' ] 
    then
        #echo "File Found" $file


        if [ $1/$file = *"~" ] && [ -e $1/$file]; then
            toDelete="y"
            if [ "$Inter" = "i" ]; then
                echo "Do you want to delete the file (enter y/n)?:  $1/$file"
                read toDelete
            else
            if test $toDelete = "y"; then
                if [ "$Quiet" != "q" ]; then
                    echo "Deleted File: " $1/$file
                fi
                rm $1/$file
                NumFiles=$((NumFiles+1))
            fi  
            fi
        fi
        
        if [ $1/$file = *"#" ] && [ -e $1/$file]; then
            toDelete="y"
            if [ "$Inter" = "i" ]; then
                echo "Do you want to delete the file (enter y/n)?:  $1/$file"
                read toDelete
            else
            if test $toDelete = "y"; then
                if [ "$Quiet" != "q" ]; then
                    echo "Deleted File: " $1/$file
                fi
                rm $1/$file
                NumFiles=$((NumFiles+1))
            fi  
            fi
        fi

        if [ $1/$file = *".o" ] && [ -e $1/$file]; then
            toDelete="y"
            if [ "$Inter" = "i" ]; then
                echo "Do you want to delete the file (enter y/n)?:  $1/$file"
                read toDelete
            else
            if test $toDelete = "y"; then
                if [ "$Quiet" != "q" ]; then
                    echo "Deleted File: " $1/$file
                fi
                rm $1/$file
                NumFiles=$((NumFiles+1))
            fi  
            fi
        fi

        if [ $1/$file != *"."* ] && [ $1/$file != *"Makefile" ] && [ -e $1/$file ]; then
            toDelete="y"
            # echo "Inter value: "$Inter
            # echo "Quiet: "$Quiet
            # echo "toDelete: "$toDelete
            # echo "Stats: "$Stats
            if [ "$Inter" = "i" ]; then
                echo "Do you want to delete the file (enter y/n)?:  $1/$file"
                read toDelete
            else
            if test $toDelete = "y"; then
                if [ "$Quiet" != "q" ]; then
                    echo "Deleted File: " $1/$file
                fi
                rm $1/$file
                NumFiles=$((NumFiles+1))
            fi  
            fi
        fi

        if [ $1/$file = "core" ] && [ test -e $1/$file]; then
            toDelete="y"
            if [ "$Inter" = "i" ]; then
                echo "Do you want to delete the file (enter y/n)?:  $1/$file"
                read toDelete
            else
            if test $toDelete = "y"; then
                if [ "$Quiet" != "q" ]; then
                    echo "Deleted File: " $1/$file
                fi
                rm $1/$file
                NumFiles=$((NumFiles+1))
            fi  
            fi
        fi

    fi
done
}





i=""
q=""
s=""


for var in "$@"
do

    if test $var = "-i" || test $var = "--interactive" ; then
        unset i
        i="i"  
    fi
    if test $var = "-q" || test $var = "--quiet" ; then
        unset q
        q="q" 
    fi
    if test $var = "-s" || test $var = "--stats"; then
        echo "Size Before: " && du -sh * | grep 20191
        unset s
        s="s"

    fi
done

clean_files $1 $i $q $s $NumFiles

if [ "$s" = "s" ]; then
    echo "Number of Files deleted: " $NumFiles
    echo "Size After: " && du -sh * | grep 20191
fi 





