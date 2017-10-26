<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="fr" >

  <title> Acupuncteurs en médecine traditionnelle chinoise </title>
  <meta name="description" content="Acupuncteurs en médecine traditionnelle chinoise" />
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <link rel="stylesheet" media="screen" type="text/css" href="../css/style.css" />

  {include file='./header.tpl'}

  <body>


     <nav>
        <ul>
          <li> <a accesskey="1" href="index.php?page=accueil">Page d'accueil (1) </a> </li>
          <li> <a class="active"  accesskey="2" href="index.php?page=categorie">Accès aux données (2)</a> </li>
          <li> <a accesskey="3" href="index.php?page=info">Page d'information (3) </a> </li>
          <li> <a accesskey="4" href="index.php?page=rss">RSS (4)</a> </li>
          <li id="connex" accesskey="5"> {connexion} </li>

        </ul>
     </nav>
     <div class="gros_titre">
       <h1>ACUPUNCTURE</h1>

       <h2>Liste des pathologies</h2>
     </div>
      
      <div class="para">
        {if isset($smarty.session.login)}
        <h3> Filtrage </h3>
          <form method="post" id='recherche' action="index.php?page=categorie">
                <label for="champ_recherche">Recherche par mots clés: </label>
                <input type="text" id="champ_recherche" name="champ_recherche"/>

               {filtre_categorie}

               <label>Méridien:</label>
               <select name="meridien" id="meridien">
                  <option value=""> Aucun </option>
                  {foreach from=$liste_categorie item=categorie}
                     <option value="{$categorie.Categorie}"> {$categorie.Categorie} </option>
                  {/foreach}
               </select>

               <label>Type de pathologie:</label>
               <select name="type" id="type">
                      <option value=""> Aucun </option>
                      <option value="meridien"> méridien </option>
                      <option value="meridien"> organe/viscere </option>
                      <option value="luo"> luo </option>
                      <option value="merveilleux vaisseaux"> merveilleux vaisseaux </option>
                      <option value="jing jin"> jing jin </option>
                </select>

                <label>Caractéristiques:</label>
                 <select name="caracteristique" id="caracteristique">
                       <option value=""> Aucune </option>
                       <option value="plein"> plein </option>
                       <option value="chaud"> chaud </option>
                       <option value="vide"> vide </option>
                       <option value="froid"> froid </option>
                       <option value="interne"> interne </option>
                       <option value="externe"> externe </option>
                </select>
               <input type="submit" value="Rechercher"/>
        </form>
     
      {/if}

    
    
     <h3> Affichage </h3>

      {pathologie}

      <table>
          <thead>
              <tr>
                  <th id="pathologie">Pathologie</th>
                  <th id="symptome">Symptome</th>
              </tr>
          </thead>
          <tbody class="tableau">
              {foreach from=$liste_patho item=patho}
                <tr>
                  <td>{$patho.Pathologie} </td>
                  <td>{$patho.Symptome} </td>
                </tr>
             {/foreach}
        </tbody>
      </table>
    </div>
    

      {include file='./footer.tpl'}

    <script src="https://code.jquery.com/jquery-1.12.4.js"></script>
    <script src="https://code.jquery.com/ui/1.12.1/jquery-ui.js"></script>
    <script type='text/javascript' src='../js/filtre.js'></script>

  </body>
</html>
