<?php
/* Smarty version 3.1.31, created on 2017-02-12 16:24:15
  from "C:\wamp\www\accueil.php" */

/* @var Smarty_Internal_Template $_smarty_tpl */
if ($_smarty_tpl->_decodeProperties($_smarty_tpl, array (
  'version' => '3.1.31',
  'unifunc' => 'content_58a07e1f3d9270_11025209',
  'has_nocache_code' => false,
  'file_dependency' => 
  array (
    'abca3473c50c93f1f76a6e14d35127ae42b162f5' => 
    array (
      0 => 'C:\\wamp\\www\\accueil.php',
      1 => 1486744118,
      2 => 'file',
    ),
  ),
  'includes' => 
  array (
  ),
),false)) {
function content_58a07e1f3d9270_11025209 (Smarty_Internal_Template $_smarty_tpl) {
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

      <?php echo '<?php ';?>if(!isset($_SESSION['login'])) : <?php echo '?>';?>
      <li> <a href="index.php?page=connexion">Se connecter </a> </li>
      <?php echo '<?php ';?>endif; <?php echo '?>';?>

      <?php echo '<?php ';?>if(isset($_SESSION['login'])) : <?php echo '?>';?>
      <li> <a href="index.php?page=deconnexion">Se déconnecter </a> </li>
      <?php echo '<?php ';?>endif; <?php echo '?>';?>
      
    </ul>
   </nav>


   <!-- FORMULAIRE D'INSCRIPTION -->
<?php echo '<?php ';?>if(!isset($_SESSION['login'])) : <?php echo '?>';?>
   
    <h1>  Inscription </h1>
<form method="post" action="inscription-source.php">


          <!-- LIEN AVEC LA CIBLE PHP QUI RECOIT LES DONNES DU  FORMULAIRE -->
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
     
      <li>
        <input type="submit" value="Confirmer l inscription" /> 
      </li>
    </ul>
  </form>

     <?php echo '<?php ';?>endif; <?php echo '?>';?>


</body><?php }
}
