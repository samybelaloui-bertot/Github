<?php
/* Smarty version 3.1.31, created on 2017-02-14 16:21:06
  from "/Applications/MAMP/bin/mamp/connexion.tpl" */

/* @var Smarty_Internal_Template $_smarty_tpl */
if ($_smarty_tpl->_decodeProperties($_smarty_tpl, array (
  'version' => '3.1.31',
  'unifunc' => 'content_58a320629b6ba5_45588251',
  'has_nocache_code' => false,
  'file_dependency' => 
  array (
    '6ca0a6f10dd11f2f02b259b9f92cb81c93c341b4' => 
    array (
      0 => '/Applications/MAMP/bin/mamp/connexion.tpl',
      1 => 1487012078,
      2 => 'file',
    ),
  ),
  'includes' => 
  array (
  ),
),false)) {
function content_58a320629b6ba5_45588251 (Smarty_Internal_Template $_smarty_tpl) {
?>
<!-- FORMULAIRE DE CONNEXION -->
    <h1>  Connexion </h1>

    <form method="post" action="connexion-source.php">       <!-- LIEN AVEC LA CIBLE PHP QUI RECOIT LES DONNES DU  FORMULAIRE -->
    <ul>
      <li>
        <label for="login">Login&nbsp;:</label>
        <input type="text" id="login" name="login" placeholder="Dupont" required>
      </li>
      <li>
        <label for="password">Mot de passe&nbsp;:</label>
        <input type="password" id="password" name="password" required>
      </li>
           
      <input type="submit" value="Connexion" /> 
    
    </ul>
  </form><?php }
}
