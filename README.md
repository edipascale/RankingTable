RankingTable - A C++ implementation of a mutable ranking table based on 
boost::bimap

Copyright 2014 Emanuele Di Pascale, CTVR - Trinity College Dublin
See LICENSE.txt for details on licensing. 

This table keeps track of the number of hits (or views) received by its elements
and allows for instantaneous mapping from element to rank (and vice-versa).
The assumption is that hits are incremental and unitary. 
The code was quickly and roughly unit-tested but it was not designed for
production use and it's released with no warranty whatsoever - use at your own
risk!