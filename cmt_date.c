dpush() {
    git add .
    if [ "$1" != "" ]
    then
        git commit --date='2022-07-17 11:11:11' --file comment.txt
    else
        git commit --date='2022-07-17 11:11:11' --file comment.txt
    fi
    git push
}
