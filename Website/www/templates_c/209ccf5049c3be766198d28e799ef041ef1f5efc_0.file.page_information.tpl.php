<?php
/* Smarty version 3.1.31, created on 2017-02-16 08:44:55
  from "C:\wamp\www\page_information.tpl" */

/* @var Smarty_Internal_Template $_smarty_tpl */
if ($_smarty_tpl->_decodeProperties($_smarty_tpl, array (
  'version' => '3.1.31',
  'unifunc' => 'content_58a558774cf294_01628259',
  'has_nocache_code' => false,
  'file_dependency' => 
  array (
    '209ccf5049c3be766198d28e799ef041ef1f5efc' => 
    array (
      0 => 'C:\\wamp\\www\\page_information.tpl',
      1 => 1487230780,
      2 => 'file',
    ),
  ),
  'includes' => 
  array (
  ),
),false)) {
function content_58a558774cf294_01628259 (Smarty_Internal_Template $_smarty_tpl) {
if (!is_callable('smarty_function_connexion')) require_once 'C:\\wamp\\www\\smarty\\plugins\\function.connexion.php';
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
       <h1>Page d'information</h1>
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

    </nav>
</body><?php }
}
