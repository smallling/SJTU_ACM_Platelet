" vimrc
set number
set cindent
set expandtab
set showcmd
set showmatch
set hlsearch
set ts=4
set shiftwidth=4
set softtabstop=4

vmap <C-C> "+y
vmap <C-V> "_d"+p
nmap <C-A> ggVG
nmap <C-V> "+p

autocmd filetype cpp map <F9> :w<CR>:!g++ % -std=c++14 -O2 && ./a.out<CR>
autocmd filetype cpp map <S-F9> :w<CR>:!g++ % -std=c++14 -O2 && time ./a.out < in<CR>
autocmd filetype cpp map <C-S-F9> :w<CR>:!g++ % -std=c++14 -O2 && time ./a.out < 

autocmd filetype python map <F9> :w<CR>:!python %<CR>
autocmd filetype python map <S-F9> :w<CR>:!time python % < in<CR>
autocmd filetype python map <C-S-F9> :w<CR>:!time python % < 

autocmd filetype java map <F9> :w<CR>:!javac % && java %<<CR>
autocmd filetype java map <S-F9> :w<CR>:!javac % && time java %< < in<CR>
autocmd filetype java map <C-S-F9> :w<CR>:!javac % && time java %< < 
