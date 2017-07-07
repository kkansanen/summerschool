program hello
  implicit none
  real :: x, y
  integer :: i = 5
  integer :: j
  real :: z(1000) = (/(j, j=1,1000)/)
  write (*,*) 'Hello world from Fortran!'
  x = 2.0**i
  y = 2.0**real(i)
  write (*,*) '2.0**i = ', x
  write (*,*) '2.0**real(i) = ', y
  write (*,*) 'x+y = ', x+y
  write (*,*) 'z(1 : 1000 : 5) = ', z ( 1 : 1000 : 5 )


end program hello
