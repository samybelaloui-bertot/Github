<?php
/* Smarty version 3.1.31, created on 2017-02-14 16:20:52
  from "/Applications/MAMP/bin/mamp/accueil.tpl" */

/* @var Smarty_Internal_Template $_smarty_tpl */
if ($_smarty_tpl->_decodeProperties($_smarty_tpl, array (
  'version' => '3.1.31',
  'unifunc' => 'content_58a320543fb902_00600779',
  'has_nocache_code' => false,
  'file_dependency' => 
  array (
    '2318566d6c2e17976e8435d0a6c523de45f17118' => 
    array (
      0 => '/Applications/MAMP/bin/mamp/accueil.tpl',
      1 => 1487021762,
      2 => 'file',
    ),
  ),
  'includes' => 
  array (
  ),
),false)) {
function content_58a320543fb902_00600779 (Smarty_Internal_Template $_smarty_tpl) {
if (!is_callable('smarty_function_connexion')) require_once '/Applications/MAMP/bin/mamp/smarty/plugins/function.connexion.php';
?>
<!DOCTYPE html>

<html lang="fr">
<head>
  <title> Acupuncteurs en médecine traditionnelle chinoise </title>
  <meta name="description" content="Acupuncteurs en médecine traditionnelle chinoise" />
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <link href="style_AAA.css" rel="stylesheet" type="text/css"/>
</head>

<body>
   <header>
       <h1>  Association des acupuncteurs soucieux de l’accessibilité </h1>
   </header>

   <nav>
    <ul>
      <li> <a href="index.php?page=accueil">Page d'accueil </a> </li>
      <li> <a href="index.php?page=categorie">Catégorie de pathologie</a> </li>
      <li> <a href="index.php?page=recherchepatho">Recherche de pathologie</a> </li>
      <li> <a href="index.php?page=info">Page d'information</a> </li>
      <li> <?php echo smarty_function_connexion(array(),$_smarty_tpl);?>
 </li>      
   </nav>

    <?php if (!isset($_SESSION['login'])) {?>
      <h1>  Inscription </h1>
      <form method="post" action="inscription-source.php">
      <ul>
        <li>
          <label for="login">Login&nbsp;:</label>
          <input type="text" id="login" name="login" placeholder="Dupont" required>
        </li>
        <li>
          <label for="email">Adresse e-mail&nbsp;:</label>
          <input type="email" id="email_addr" name="email_addr" required>
        </li>
        <li>
          <label for="email_addr_repeat">Confirmez l adresse e-mail&nbsp;:</label>
          <input type="email" id="email_addr_repeat" name="email_addr_repeat" required 
          oninput="check(this)">
        </li>
        <li>
          <label for="password">Mot de passe&nbsp;:</label>
          <input type="password" id="password" name="password" required>
        </li>
        <li>
          <label for="password_repeat">Confirmez le mot de passe&nbsp;:</label>
          <input type="password" id="password_repeat" name="password_repeat" required 
          oninput="check(this)">
        </li>

        <input type="submit" value="Confirmer l inscription" /> 
     
      </ul>
      </form>
    <?php }?>

    <?php if (isset($_SESSION['login'])) {?>
      <form method="post" action="gestion_recherche.php">
          <label for="recherche">Recherche&nbsp;:</label>
          <input type="text" id="recherche" name="recherche" placeholder="Pathologie" required>
      </form>
    <?php }?>

  </body><?php }
}
