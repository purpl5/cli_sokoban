date_maintenant=$(date "+%F-%H-%M-%S")
tar -cf ./archive/archive-$date_maintenant.tar ./header ./src ./doc makefile doxyfile