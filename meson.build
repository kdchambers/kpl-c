project('kpl-c', 'c')

kpl_sources = files(
  'src/kpl_arena.c',
  'src/kpl_alloc.c',
  'src/kpl_timer.c',
  'src/kpl_assert.c',
  'src/kpl_mem.c',
  'src/kpl_random.c',
)

kpl_inc_dirs = 'include'
kpl_args = ['-std=c23']

kpl_lib = static_library('kpl', kpl_sources, 
                          c_args : kpl_args,
                          include_directories : kpl_inc_dirs)

