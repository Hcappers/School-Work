!=======================================================================
!        Calculates Machine Epsilon 
!....&---1---------2---------3---------4---------5---------6---------7--
!####&###1#########2#########3#########4#########5#########6#########7##
         program m_epsilon
         real(kind(1.0)) :: eps, one, two
         integer :: temp
c aaaa
* aaaa
         eps = 1.0
         one = 1.0
         two = 2.0

         do while(one+eps .GT. one)
            eps = eps/two
         enddo
         eps=two*eps 

         temp = int(log(eps)/log(two))

         write(*,*)
         write(*,*)'Machine Epsilon from Fortran code:'
         write(*,'(a,es23.16, a, i3)') ' eps =', eps, ' = 2^', temp 
         write(*,*)

        stop

      end program m_epsilon
!_______________________________________________________________________
!####.###1#########2#########3#########4#########5#########6#########7##

