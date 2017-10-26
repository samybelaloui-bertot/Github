--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   08:45:50 02/16/2016
-- Design Name:   
-- Module Name:   C:/CPE_users/TP_ELN2/Groupe D/BELALOUI-CHAVRET/Projet1/chronoscore/transcoder_2v4_tb.vhd
-- Project Name:  chronoscore
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: transcoder_2v4
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
 
ENTITY transcoder_2v4_tb IS
END transcoder_2v4_tb;
 
ARCHITECTURE behavior OF transcoder_2v4_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT transcoder_2v4
    PORT(
         A : IN  std_logic_vector(1 downto 0);
         O : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic_vector(1 downto 0) := (others => '0');

 	--Outputs
   signal O : std_logic_vector(3 downto 0);
 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: transcoder_2v4 PORT MAP (
          A => A,
          O => O
        );

A <="00" after 0 ns,
	"01" after 20 ns,
	"10" after 40 ns,
	"11" after 60 ns;

END;