--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   20:40:47 02/26/2016
-- Design Name:   
-- Module Name:   C:/Users/samyb/Documents/CPE/Electronique/Projet1/chronoscore/register_1b_tb.vhd
-- Project Name:  chronoscore
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: register_1b
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY register_1b_tb IS
END register_1b_tb;
 
ARCHITECTURE behavior OF register_1b_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT register_1b
    PORT(
         D : IN  std_logic;
         clk : IN  std_logic;
         Q : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal D : std_logic := '0';
   signal clk : std_logic := '0';

 	--Outputs
   signal Q : std_logic;

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN

	D <= '1' after 20 ns,
	'0' after 60 ns,
	'1' after 80 ns;
 
	-- Instantiate the Unit Under Test (UUT)
   uut: register_1b PORT MAP (
          D => D,
          clk => clk,
          Q => Q
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for clk_period*10;

      -- insert stimulus here 

      wait;
   end process;

END;
