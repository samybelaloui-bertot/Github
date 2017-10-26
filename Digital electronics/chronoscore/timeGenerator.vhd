----------------------------------------------------------------------------------
-- 
-- Engineer:       Renaud DAVIOT
-- 
-- Create Date:    2016 
--
-- Module Name:    timeGenerator - Behavioral 
-- Project Name:   Chronoscore_VGA
--
-- Target Devices: XC3S200 (Spartan 3 - 200K)
-- 
-- Description: 
--
--
-- Revision 0.01 - File Created
--
----------------------------------------------------------------------------------

library IEEE;
    use IEEE.STD_LOGIC_1164.ALL;

entity timeGenerator is
    Port (  GCLK   : in  std_logic;
            CE_1ms : out std_logic;
            CE_1s  : out std_logic;
            CLK    : out std_logic);
end timeGenerator;

architecture Behavioral of timeGenerator is

    component DLL
        Port ( GCLK       : in  std_logic;
               CLK        : out std_logic);
    end component DLL;
    
    component timer_1s
        Port (  CLK       : in  STD_LOGIC;
                T_out     : out STD_LOGIC);
    end component timer_1s;
    
    component timer_1ms
        Port (  CLK       : in  STD_LOGIC;
                T_out     : out STD_LOGIC);
    end component timer_1ms;


    -----------------------------------------------

    signal clk_int   : std_logic;
    
    -----------------------------------------------

begin

    U0 : DLL 
        port map (  GCLK       => GCLK,
                    CLK        => clk_int);                

    U1 : timer_1s 
        port map (  CLK        => clk_int,
                    T_out      => CE_1s);
                    
    U2 : timer_1ms 
        port map (  CLK        => clk_int,
                    T_out      => CE_1ms);
                    
    CLK <= clk_int;
                                
end Behavioral;

