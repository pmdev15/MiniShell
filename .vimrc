source $VIMRUNTIME/vimrc_example.vim

set noerrorbells
set hls
set is
set cb=unnamed
set gfn=Monospace:h12
set ts=4
set sw=4
set si
set history=1000
cd ~/Desktop/pullak

filetype plugin on
filetype on

map <C-n> :NERDTreeToggle<CR>
let g:NERDTreeWinPos = "left"

"name plugin
let g:vimrc_author="Pullak"
let g:vimrc_email='pmdev1566@gmail.com'
let g:vimrc_homepage=''

nmap <F4> :AuthorInfoDetect <cr>


set nu rnu " relative line numbering
set clipboard=unnamed " public copy/paste register
set ruler
set showcmd
set noswapfile " doesn't create swap files
set nobackup
set undodir=
set undofile
set incsearch
set noshowmode
set shortmess+=c
set omnifunc=syntaxcomplete#Complete

set backspace=indent,eol,start " let backspace delete over lines
set autoindent " enable auto indentation of lines
set smartindent " allow vim to best-effort guess the indentation

set noundofile
set lazyredraw "redraws the screne when it needs to
set showmatch "highlights matching brackets
set incsearch "search as characters are entered
set hlsearch "highlights matching searches

" Enable folding
set foldmethod=indent
set foldlevel=99
"Enable folding with the spacebar
nnoremap <space> za

syntax on
filetype on
set nobackup
highlight Comment cterm=italic gui=italic

set laststatus=2

inoremap { {}<Left>
inoremap {<CR> {<CR>}<Esc>O
inoremap {{ {
inoremap {} {}

autocmd filetype cpp nnoremap <C-P> :w <bar> !g++ -std=c++14 % -o %:r -Wl,--stack,268435456<CR>
autocmd filetype cpp nnoremap <C-L> :!%:r<CR>
autocmd filetype cpp nnoremap <C-C> :s/^\(\s*\)/\1\/\/<CR> :s/^\(\s*\)\/\/\/\//\1<CR> $
autocmd filetype c nnoremap <C-P> :w <bar> !gcc % -o %:r<CR>
autocmd filetype c nnoremap <C-L> :!%:r<CR>

colorscheme molokai


" true colours
set background=dark
set t_Co=256

set nu
augroup numbertoggle
    autocmd!
    autocmd BufEnter,FocusGained,InsertLeave * set rnu
    autocmd BufLeave,FocusLost,InsertEnter * set nornu
augroup END



" PLUGINS ---------------------------------------------------------------- {{{

call plug#begin('~/.vim/plugged')


  Plug 'dense-analysis/ale'

  Plug 'preservim/nerdtree'

  Plug 'itchyny/lightline.vim'

  Plug 'junegunn/fzf'
  Plug 'junegunn/fzf.vim'
  Plug 'ervandew/supertab'
  Plug 'neoclide/coc.nvim', {'branch': 'release'}
	
call plug#end()
" }}}


" VIMSCRIPT -------------------------------------------------------------- {{{

" Enable the marker method of folding.
augroup filetype_vim
    autocmd!
    autocmd FileType vim setlocal foldmethod=marker
augroup END


" If Vim version is equal to or greater than 7.3 enable undofile.
" This allows you to undo changes to a file even after saving it.
if version >= 703
    set undodir=~/.vim/backup
    set undofile
    set undoreload=10000
endif


" If GUI version of Vim is running set these options.
if has('gui_running')

    " Set the background tone.
    set background=dark

    " Set the color scheme.
    colorscheme molokai

    " Set a custom font you have installed on your computer.
    " Syntax: set guifont=<font_name>\ <font_weight>\ <size>
    set guifont=Monospace\ Regular\ 12 

endif

" }}}


let g:lightline = {
      \ 'colorscheme': 'wombat',
      \ 'active': {
      \   'left': [ ['mode', 'paste'],
      \             ['fugitive', 'readonly', 'filename', 'modified'] ],
      \   'right': [ [ 'lineinfo' ], ['percent'] ]
      \ }
      \ }
