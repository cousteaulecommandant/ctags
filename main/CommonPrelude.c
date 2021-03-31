const char ctagsCommonPrelude []=
"%\n"
"% Copyright (c) 2021, Masatake YAMATO\n"
"% Copyright (c) 2021, Red Hat, Inc.\n"
"%\n"
"% This source code is released for free distribution under the terms of the\n"
"% GNU General Public License version 2 or (at your option) any later version.\n"
"%\n"
"\n"
"%\n"
"% The documentation table\n"
"%\n"
"\n"
"% __PROCDOCS:dict<proc:name, doc:string>\n"
"/__procdocs 30 dict def\n"
"\n"
"% name value __BDEF -\n"
"/__bdef { bind def }  bind def\n"
"\n"
"% doc:string key:name any:val __DOCDEF -\n"
"/__bddef {\n"
"    1 index exch __bdef\n"
"    exch __procdocs 3 1 roll put\n"
"} __bdef\n"
"\n"
"\n"
"%\n"
"% procedures\n"
"%\n"
"(any n:int _NDUP any1 ... anyn)\n"
"/_ndup { { dup } repeat } __bddef\n"
"\n"
"(x:any x:any _DEDUP x:any\n"
" x:any y:any _DEDUP x:any y:any)\n"
"/_dedup {\n"
"    count 1 gt {\n"
"        2 copy eq {\n"
"            pop\n"
"        } if\n"
"    } if\n"
"} __bddef\n"
"\n"
"(space:int space:int _DEDUP_SPACES space:int\n"
" otherthanspace:int space:int _DEDUP_SPACES otherthanspace:int space:int)\n"
"/_dedup_spaces {\n"
"    count 0 gt {\n"
"        dup ?\\_ eq {\n"
"            _dedup\n"
"        } if\n"
"    } if\n"
"} __bddef\n"
"\n"
"% 32 32 _dedup_spaces pstack clear (---) ==\n"
"% 32 41 _dedup_spaces pstack clear (---) ==\n"
"% 41 32 _dedup_spaces pstack clear (---) ==\n"
"% 32 _dedup_spaces pstack clear (---) ==\n"
"% 41 _dedup_spaces pstack clear (---) ==\n"
"% quit\n"
"\n"
"/__buildstring {\n"
"    {\n"
"	    counttomark dup 1 eq {\n"
"	        pop exch pop\n"
"	        exit\n"
"	    } {\n"
"	        -1 roll 1 index exch _putlast!\n"
"	    } ifelse\n"
"    } loop\n"
"} __bdef\n"
"\n"
"(mark char:int|substring:string... _BUILDSTRING string)\n"
"/_buildstring {\n"
"    0 string __buildstring\n"
"} __bddef\n"
"\n"
"(string char:int|string _PUTLAST! -)\n"
"/_putlast!  {\n"
"    1 index length exch\n"
"    dup type /integertype eq {\n"
"	    put\n"
"    } {\n"
"	    putinterval\n"
"    } ifelse\n"
"} __bddef\n"
"\n"
"(target:string fromto:str _TR! -)\n"
"/_tr! {\n"
"    %\n"
"    % () is not allowed.\n"
"    % The reason must be be documented.\n"
"    %\n"
"    0 string\n"
"    % str [int<from> int<to>] str'\n"
"    2 index {\n"
"	% str [int<from> int<to>] str' int<chr>\n"
"	    dup 3 index 0 get\n"
"	% str [int<from> int<to>] str' int<chr> int<chr> int<from>\n"
"	    eq {% str [int<from> int<to>] str' int<chr>\n"
"	        pop\n"
"	        dup 2 index 1 get _putlast!\n"
"	    } {% str [int<from> int<to>] str' int<chr>\n"
"	        1 index exch _putlast!\n"
"	    } ifelse\n"
"    } forall\n"
"    % str [int<from> int<to>] str'\n"
"    exch pop\n"
"    0 exch putinterval\n"
"} __bddef\n"
"\n"
"(string _NORMALIZE_SPACES! -)\n"
"/_normalize_spaces! {\n"
"    dup\n"
"    dup (\\n ) _tr!\n"
"    dup (\\t ) _tr!\n"
"    dup (\\r ) _tr!\n"
"    dup (\\f ) _tr!\n"
"    dup (\\v ) _tr!\n"
"    mark exch { _dedup_spaces } forall _buildstring\n"
"    exch copy pop\n"
"} __bddef\n"
"\n"
"% /x mark 40 (a) 32 32 10 (b) 10 10 9 9 (xyz) 9 9 41 _buildstring def\n"
"% x _normalize_spaces! x pstack\n"
;
