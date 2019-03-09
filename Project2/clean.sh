#!/bin/bash
# Justin Baskaran
# CS 232- Project 2
# March 06, 2019
NumFiles=0

clean_files () {
DIR=$1/*
Inter=""
Quiet=""
Stats=""
for var in "$@"
do
    if [[ $var == "i" ]]; then
        unset Inter
        Inter="i"  
    fi
    if [[ $var == "q" ]]; then
        unset Quiet
        Quiet="q" 
    fi
    if [[ $var == "s" ]]; then
        unset Stats
        Stats="s"

    fi
done

for file in $DIR; do
    if [ -d $file ] ; then
        clean_files $file $Inter $Quiet $Stats $NumFiles
    else 
        if [[ $file == *"~" && -e $file ]]; then
            if [[ $Quiet != "q" ]]; then
                echo "Deleted File: " $file
            fi
            if [[ $Inter == "i" ]]; then
                echo "Do you want to delete the file (enter y/n)?:  $file"
                read toDelete
                if [[ $toDelete == "y" ]]; then
                    rm $file
                    let "NumFiles=NumFiles+1"
                else
                    echo "Did not delete: $file"
                    
                fi
            else    
                rm $file
                let "NumFiles=NumFiles+1"
            fi
        fi
        
        if [[ $file == *"#" && -e $file ]]; then
            if [[ $Quiet != "q" ]]; then
                echo "Deleted File: " $file
            fi
            if [[ $Inter == "i" ]]; then
                echo "Do you want to delete the file (enter y/n)?:  $file"
                read toDelete
                if [[ $toDelete == "y" ]]; then
                    rm $file
                    let "NumFiles=NumFiles+1"
                else
                    echo "Did not delete: $file"
                    
                fi
            else    
                rm $file
                let "NumFiles=NumFiles+1"
            fi
        fi

        if [[ $file == *".o" && -e $file ]]; then
            if [[ $Quiet != "q" ]]; then
                echo "Deleted File: " $file
            fi
            if [[ $Inter == "i" ]]; then
                echo "Do you want to delete the file (enter y/n)?:  $file"
                read toDelete
                if [[ $toDelete == "y" ]]; then
                    rm $file
                    let "NumFiles=NumFiles+1"
                else
                    echo "Did not delete: $file"
                    
                fi
            else    
                rm $file
                let "NumFiles=NumFiles+1"
            fi
        fi

        if [[ $file != *"."* && $file != *"Makefile"*  && -e $file ]]; then
            if [[ $Quiet != "q" ]]; then
                echo "Deleted File: " $file
            fi
            if [[ $Inter == "i" ]]; then
                echo "Do you want to delete the file (enter y/n)?:  $file"
                read toDelete
                if [[ $toDelete == "y" ]]; then
                    rm $file
                    let "NumFiles=NumFiles+1"
                else
                    echo "Did not delete: $file"
                    
                fi
            else    
                rm $file
                let "NumFiles=NumFiles+1"
            fi
        fi

        if [[ $file == *"core"* && -e $file ]]; then
            if [[ $Quiet != "q" ]]; then
                echo "Deleted File: " $file
            fi
            if [[ $Inter == "i" ]]; then
                echo "Do you want to delete the file (enter y/n)?:  $file"
                read toDelete
                if [[ $toDelete == "y" ]]; then
                    rm $file
                    let "NumFiles=NumFiles+1"
                else
                    echo "Did not delete: $file"
                    
                fi
            else    
                rm $file
                let "NumFiles=NumFiles+1"
            fi
        fi

    fi
done
}

if [[ "${BASH_SOURCE[0]}" == "${0}" ]]; then
    i=""
    q=""
    s=""
    NumFiles=0
    for var in "$@"
    do
        if [[ $var == "-i" || $var == "--interactive" ]]; then
            unset i
            i="i"  
        fi
        if [[ $var == "-q" || $var == "--quiet" ]]; then
            unset q
            q="q" 
        fi
        if [[ $var == "-s" || $var == "--stats" ]]; then
            echo "Size Before: " && du -sh * | grep 20191
            unset s
            s="s"

        fi
    done
    
    clean_files $1 $i $q $s $NumFiles
    echo "Total "$NumFiles
    
    if [[ $s == "s" ]]; then
        echo "Number of Files deleted: " $NumFiles
        echo "Size After: " && du -sh * | grep 20191
    fi 

    
    
fi


