library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

use work.f32c_pack.all;


entity arduino is
    generic (
	C_clk_freq: integer := 81;
	-- SoC configuration options
	C_bram_size: integer := 16;
	C_gpio: integer := 29
    );
    port (
	clk_25m: in std_logic;
	rs232_tx: out std_logic;
	rs232_rx: in std_logic;
	j1_2, j1_3, j1_4, j1_8, j1_9, j1_13, j1_14, j1_15: inout std_logic;
	j1_16, j1_17, j1_18, j1_19, j1_20, j1_21, j1_22, j1_23: inout std_logic;
	j2_2, j2_3, j2_4, j2_5, j2_6, j2_7, j2_8, j2_9: inout std_logic;
	j2_10, j2_11, j2_12, j2_13, j2_16: inout std_logic;
	led: out std_logic_vector(7 downto 0);
	btn_left, btn_right, btn_up, btn_down, btn_center: in std_logic;
	sw: in std_logic_vector(3 downto 0);
	p_tip: out std_logic_vector(3 downto 0);
	p_ring: out std_logic
    );
end arduino;

architecture x of arduino is
    signal clk, rs232_break: std_logic;
    signal btns: std_logic_vector(4 downto 0);
    signal code_left, code_right: std_logic_vector(7 downto 0);
    signal tone_left, tone_right: std_logic;
begin
    -- clock synthesizer: Lattice XP2 specific
    clkgen: entity work.clkgen
    generic map (
	C_clk_freq => C_clk_freq
    )
    port map (
	clk_25m => clk_25m, clk => clk, clk_325m => open,
	ena_325m => '0', res => rs232_break
    );

    -- f32c system-on-a-chip glue logic
    f32c_soc_glue: entity work.f32c_soc_glue
    generic map (
	C_clk_freq => C_clk_freq,
	C_bram_size => C_bram_size,
	C_gpio => C_gpio
    )
    port map (
	clk => clk,
	sio_txd(0) => rs232_tx, sio_rxd(0) => rs232_rx,
	sio_break(0) => rs232_break,
	-- Prikljucnice za prosirenje, GPIO
	gpio(0) => j1_2, gpio(1) => j1_3,
	gpio(2) => j1_4, gpio(3) => j1_8,
	gpio(4) => j1_9, gpio(5) => j1_13,
	gpio(6) => j1_14, gpio(7) => j1_15,
	gpio(8) => j1_16, gpio(9) => j1_17,
	gpio(10) => j1_18, gpio(11) => j1_19,
	gpio(12) => j1_20, gpio(13) => j1_21,
	gpio(14) => j1_22, gpio(15) => j1_23,
	gpio(16) => j2_2, gpio(17) => j2_3,
	gpio(18) => j2_4, gpio(19) => j2_5,
	gpio(20) => j2_6, gpio(21) => j2_7,
	gpio(22) => j2_8, gpio(23) => j2_9,
	gpio(24) => j2_10, gpio(25) => j2_11,
	gpio(26) => j2_12, gpio(27) => j2_13,
	gpio(28) => j2_16,
	-- Izlazi
	simple_out(31 downto 24) => code_left,
	simple_out(23 downto 16) => code_right,
	simple_out(15 downto 8) => open,
	simple_out(7 downto 0) => led,
	-- Ulazi
	simple_in(31 downto 20) => open,
	simple_in(19 downto 16) => sw,
	simple_in(15 downto 5) => open,
	simple_in(4 downto 0) => btns,
	-- Sucelje za prosirenje, trenutno "u zraku"
	io_address => open,
	io_strobe => open,
	io_byte_we => open,
	io_data_out => open,
	io_data_in => open
    );

    btns <= btn_center & btn_up & btn_down & btn_left & btn_right;

    tonegen_left: entity work.tonegen
    port map (
    	clk => clk,
	code => code_left(6 downto 0),
	volume => "01",
	tone_out => tone_left
    );

    tonegen_right: entity work.tonegen
    port map (
    	clk => clk,
	code => code_right(6 downto 0),
	volume => "01",
	tone_out => tone_right
    );

    p_tip <= (others => (tone_left and clk));
    p_ring <= tone_right and clk;
end x;
