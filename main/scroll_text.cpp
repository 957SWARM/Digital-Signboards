
#include <Adafruit_Protomatter.h>

extern Adafruit_Protomatter matrix;

extern String scrolltext;
extern int stRuns;
extern int runs;
extern int stlength;
extern int str_len;

extern void fun(int del_len);

void drawSponsors (void){
  scrolltext = "          West Albany High School/South Albany High School/Albany Public Schools Foundation/Redhawk Flight Club/Knife River/HP Inc./No Dinx/Argosy Foundation/LAM Research/Autodesk/Tektronix/Linn County Fair, Albany, OR/Benton County Fair Corvallis, OR/Albany Parks & Recreation/Altrusa International Foundation/Harbor Freight/CADD Connection, BIM Connection/Concept Systems/First Force/FIRST/Intel/Oregon Robotics Tournament & Outreach Program/Nuscale/Selmet Inc/Party Perfection/Linn Veterinary Hospital P.C./Bottle Drop/KFIR 720 AM/Marie Lamfrom Foundation/Ram Steelco/Central Welding Supply/Burcham's Metals/Batteries + Bulbs/Albany American Legion Post 10/Chase Bank/Optimist Club/Nathan Guthrie/Eric Shilling/Sean & JulieBeth Wilson/Melanie Cunningham/Doug & Roberta Cogswell/Eric Chamberlain/Janice & David Brown/Ivan & Nadine/Flossie & Family/Toney Cunningham Williams/Jason Yutzie/ AND THE REST!";
  stlength = scrolltext.length();
  runs = 0;
  stRuns = 0;
  for(uint8_t x=0; x<(900); x++){
      for(uint8_t x=0; x<6; x++){
        
        matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));

        matrix.setTextSize(1);

        matrix.setCursor(2, 0);
        matrix.print("~SPONSORS~");
        
        matrix.setCursor(0-x, 8);
        matrix.print(scrolltext.charAt(stRuns));
        matrix.setCursor(6-x, 8);
        matrix.print(scrolltext.charAt(stRuns + 1));
        matrix.setCursor(12-x, 8);
        matrix.print(scrolltext.charAt(stRuns + 2));
        matrix.setCursor(18-x, 8);
        matrix.print(scrolltext.charAt(stRuns + 3));
        matrix.setCursor(24-x, 8);
        matrix.print(scrolltext.charAt(stRuns + 4));
        matrix.setCursor(30-x, 8);
        matrix.print(scrolltext.charAt(stRuns + 5));
        matrix.setCursor(36-x, 8);
        matrix.print(scrolltext.charAt(stRuns + 6));
        matrix.setCursor(42-x, 8);
        matrix.print(scrolltext.charAt(stRuns + 7));
        matrix.setCursor(48-x, 8);
        matrix.print(scrolltext.charAt(stRuns + 8));
        matrix.setCursor(54-x, 8);
        matrix.print(scrolltext.charAt(stRuns + 9));
        matrix.setCursor(60-x, 8);
        matrix.print(scrolltext.charAt(stRuns + 10));
        matrix.setCursor(66-x, 8);
        matrix.print(scrolltext.charAt(stRuns + 11));
        
        matrix.show();
        fun(5);
        
      }
      stRuns++;
      runs++;
      if(runs > 915){
        break;
      }
    }
}

void drawScrolltext(String scrolltextString){
  
  //scrolltext = "      Huzzah! how long can we make this?";
  //scrolltext = "      Lakemonsters love SWARM! ~ SAFETY THIRD!";
  //scrolltext = "      YE - 4662 ~~~ Hi Mom! Hi Dad! - ORF";
  //scrolltext = "      OBAMA - 2915 ~~~ GO HEDGEHOGS! - 2898";
  //scrolltext = "      HI MOM! IM ON TV!";
  //Q31
  //scrolltext = "      things could be going better...";
  //scrolltext = "      things ARE going slightly better"; //unused
  //scrolltext = "      AMONGUS & GLHF - 2374 ~~~  GO BB! - 5975";
  //scrolltext = "      NOTHING IN PARTICULAR - 1425 ~~~ I THINK WE'RE GOOD - 6465";
  //scrolltext = "      SPOON - 4488 ~~~ PESTO - 1540";
  //scrolltext = "      6343 SOCCER BOT ~~~ I DON'T KNOW GO RED ALLIANCE THERE YOU GO - 2471";
  //scrolltext = "      THE RIZZLER - 2635 ~~~ IT'S NEVER AS FUNNY THE 2ND TIME AROUND - 4127";
  //scrolltext = "      PESTO IS THE BESTO - 1540 ~~~ I BELIEVE THAT WE WILL WIN! - 2374";

  //scrolltext = "      Hi Mom!";
  //scrolltext = "      No swerve? - 997";
  //scrolltext = "     Stay stealthy folks! - 4089 ~~~ o7 o7 o7 o7 o7 o7 - 2898";
  //scrolltext = "     I don't know, I'm gonna be honest - 2990";

  //scrolltext = "      Alright I don't have anything - 1425";
  //scrolltext = "      Go Sam! - 7034 ~~~ Obama prism - 847";
  //scrolltext = "      Blue Thunder - 2811 ~~~ Tank Drive Forever! - 2733";
  //scrolltext = "      BLUE ALLIANCE! - 2521 ~~~ LET'S HOPE THE AUTO WORKS! - 2471";
  //scrolltext = "      PESTO IS THE BESTO - 1540 ~~~ NO RP????? - 3636";
  //scrolltext = "      We love 5468! ~~~ We're doing okay! - 6465";
  //scrolltext = "      RIZZBOT - 2635 ~~~ CLIP IT! - 3673";
  //scrolltext = "      FIMSH <3 - 5975 ~~~ AARG! - 1359";
  //scrolltext = "      It's been real.";
  //scrolltext = "      The 'S' in SWARM stands for South!";
  scrolltext = "      The 'S' in SWARM stands for South!";

  matrix.setTextSize(2);

  //Split serial input into parts by each comma in the string
  str_len = scrolltext.length();

  stlength = (str_len*12)+128;

  stRuns = 0;

  for(uint8_t x=0; x<(str_len + 1); x++){
    for(uint8_t x=0; x<12; x++){
      matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));
      matrix.setCursor(0-x, 0);
      matrix.print(scrolltext.charAt(stRuns));
      matrix.setCursor(12-x, 0);
      matrix.print(scrolltext.charAt(stRuns + 1));
      matrix.setCursor(24-x, 0);
      matrix.print(scrolltext.charAt(stRuns + 2));
      matrix.setCursor(36-x, 0);
      matrix.print(scrolltext.charAt(stRuns + 3));
      matrix.setCursor(48-x, 0);
      matrix.print(scrolltext.charAt(stRuns + 4));
      matrix.setCursor(60-x, 0);
      matrix.print(scrolltext.charAt(stRuns + 5));
      matrix.setCursor(72-x, 0);
      matrix.print(scrolltext.charAt(stRuns + 6));
      matrix.show();
      fun(8);
    }
    stRuns++;
  }
}

void drawDeclaration (int times){
  //scrolltext = "      In Congress, July 4, 1776 The unanimous Declaration of the thirteen united States of America, When in the Course of human events, it becomes necessary for one people to dissolve the political bands which have connected them with another, and to assume among the powers of the earth, the separate and equal station to which the Laws of Nature and of Nature's God entitle them, a decent respect to the opinions of mankind requires that they should declare the causes which impel them to the separation. We hold these truths to be self-evident, that all men are created equal, that they are endowed by their Creator with certain unalienable Rights, that among these are Life, Liberty and the pursuit of Happiness.--That to secure these rights, Governments are instituted among Men, deriving their just powers from the consent of the governed, --That whenever any Form of Government becomes destructive of these ends, it is the Right of the People to alter or to abolish it, and to institute new Government, laying its foundation on such principles and organizing its powers in such form, as to them shall seem most likely to effect their Safety and Happiness. Prudence, indeed, will dictate that Governments long established should not be changed for light and transient causes; and accordingly all experience hath shewn, that mankind are more disposed to suffer, while evils are sufferable, than to right themselves by abolishing the forms to which they are accustomed. But when a long train of abuses and usurpations, pursuing invariably the same Object evinces a design to reduce them under absolute Despotism, it is their right, it is their duty, to throw off such Government, and to provide new Guards for their future security.--Such has been the patient sufferance of these Colonies; and such is now the necessity which constrains them to alter their former Systems of Government. The history of the present King of Great Britain is a history of repeated injuries and usurpations, all having in direct object the establishment of an absolute Tyranny over these States. To prove this, let Facts be submitted to a candid world. ";
  stlength = scrolltext.length();
  runs = 0;
  stRuns = 0;
  for(uint8_t x=0; x<(times); x++){
      for(uint8_t x=0; x<6; x++){
        
        matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));

        matrix.setTextSize(1);

        matrix.setCursor(2, 0);
        //matrix.print("~SPONSORS~");
        
        matrix.setCursor(0-x, 4);
        matrix.print(scrolltext.charAt(stRuns));
        matrix.setCursor(6-x, 4);
        matrix.print(scrolltext.charAt(stRuns + 1));
        matrix.setCursor(12-x, 4);
        matrix.print(scrolltext.charAt(stRuns + 2));
        matrix.setCursor(18-x, 4);
        matrix.print(scrolltext.charAt(stRuns + 3));
        matrix.setCursor(24-x, 4);
        matrix.print(scrolltext.charAt(stRuns + 4));
        matrix.setCursor(30-x, 4);
        matrix.print(scrolltext.charAt(stRuns + 5));
        matrix.setCursor(36-x, 4);
        matrix.print(scrolltext.charAt(stRuns + 6));
        matrix.setCursor(42-x, 4);
        matrix.print(scrolltext.charAt(stRuns + 7));
        matrix.setCursor(48-x, 4);
        matrix.print(scrolltext.charAt(stRuns + 8));
        matrix.setCursor(54-x, 4);
        matrix.print(scrolltext.charAt(stRuns + 9));
        matrix.setCursor(60-x, 4);
        matrix.print(scrolltext.charAt(stRuns + 10));
        matrix.setCursor(66-x, 4);
        matrix.print(scrolltext.charAt(stRuns + 11));

        matrix.fillRect(0, 12, 64, 16, matrix.color565(0, 0, 0));
        
        matrix.show();
        fun(5);
        
      }
      stRuns++;
      runs++;
      if(runs > times){
        break;
      }
    }
}

void drawDeclarationFull (void){
  
  scrolltext = "      In Congress, July 4, 1776 The unanimous Declaration of the thirteen united States of America, When in the Course of human events, it becomes necessary for one people to dissolve the political bands which have connected them with another, and to assume among the powers of the earth, the separate and equal station to which the Laws of Nature and of Nature's God entitle them, a decent respect to the opinions of mankind requires that they should declare the causes which impel them to the separation. We hold these truths to be self-evident, that all men are created equal, that they are endowed by their Creator with certain unalienable Rights, that among these are Life, Liberty and the pursuit of Happiness.--That to secure these rights, Governments are instituted among Men, deriving their just powers from the consent of the governed, --That whenever any Form of Government becomes destructive of these ends, it is the Right of the People to alter or to abolish it, and to institute new Government, laying its foundation on such principles and organizing its powers in such form, as to them shall seem most likely to effect their Safety and Happiness. Prudence, indeed, will dictate that Governments long established should not be changed for light and transient causes; and accordingly all experience hath shewn, that mankind are more disposed to suffer, while evils are sufferable, than to right themselves by abolishing the forms to which they are accustomed. But when a long train of abuses and usurpations, pursuing invariably the same Object evinces a design to reduce them under absolute Despotism, it is their right, it is their duty, to throw off such Government, and to provide new Guards for their future security.--Such has been the patient sufferance of these Colonies; and such is now the necessity which constrains them to alter their former Systems of Government. The history of the present King of Great Britain is a history of repeated injuries and usurpations, all having in direct object the establishment of an absolute Tyranny over these States. To prove this, let Facts be submitted to a candid world. ";
  drawDeclaration(2150);
  fun(100);
  scrolltext = "      He has refused his Assent to Laws, the most wholesome and necessary for the public good. He has forbidden his Governors to pass Laws of immediate and pressing importance, unless suspended in their operation till his Assent should be obtained; and when so suspended, he has utterly neglected to attend to them. He has refused to pass other Laws for the accommodation of large districts of people, unless those people would relinquish the right of Representation in the Legislature, a right inestimable to them and formidable to tyrants only. He has called together legislative bodies at places unusual, uncomfortable, and distant from the depository of their public Records, for the sole purpose of fatiguing them into compliance with his measures. He has dissolved Representative Houses repeatedly, for opposing with manly firmness his invasions on the rights of the people. He has refused for a long time, after such dissolutions, to cause others to be elected; whereby the Legislative powers, incapable of Annihilation, have returned to the People at large for their exercise; the State remaining in the mean time exposed to all the dangers of invasion from without, and convulsions within. He has endeavoured to prevent the population of these States; for that purpose obstructing the Laws for Naturalization of Foreigners; refusing to pass others to encourage their migrations hither, and raising the conditions of new Appropriations of Lands. He has obstructed the Administration of Justice, by refusing his Assent to Laws for establishing Judiciary powers. He has made Judges dependent on his Will alone, for the tenure of their offices, and the amount and payment of their salaries. He has erected a multitude of New Offices, and sent hither swarms of Officers to harrass our people, and eat out their substance. He has kept among us, in times of peace, Standing Armies without the Consent of our legislatures. He has affected to render the Military independent of and superior to the Civil power. ";
  drawDeclaration(2010);
  fun(100);
  scrolltext = "      He has combined with others to subject us to a jurisdiction foreign to our constitution, and unacknowledged by our laws; giving his Assent to their Acts of pretended Legislation: For Quartering large bodies of armed troops among us: For protecting them, by a mock Trial, from punishment for any Murders which they should commit on the Inhabitants of these States: For cutting off our Trade with all parts of the world: For imposing Taxes on us without our Consent: For depriving us in many cases, of the benefits of Trial by Jury: For transporting us beyond Seas to be tried for pretended offences For abolishing the free System of English Laws in a neighbouring Province, establishing therein an Arbitrary government, and enlarging its Boundaries so as to render it at once an example and fit instrument for introducing the same absolute rule into these Colonies: For taking away our Charters, abolishing our most valuable Laws, and altering fundamentally the Forms of our Governments: For suspending our own Legislatures, and declaring themselves invested with power to legislate for us in all cases whatsoever. He has abdicated Government here, by declaring us out of his Protection and waging War against us. He has plundered our seas, ravaged our Coasts, burnt our towns, and destroyed the lives of our people. He is at this time transporting large Armies of foreign Mercenaries to compleat the works of death, desolation and tyranny, already begun with circumstances of Cruelty & perfidy scarcely paralleled in the most barbarous ages, and totally unworthy the Head of a civilized nation. He has constrained our fellow Citizens taken Captive on the high Seas to bear Arms against their Country, to become the executioners of their friends and Brethren, or to fall themselves by their Hands. He has excited domestic insurrections amongst us, and has endeavoured to bring on the inhabitants of our frontiers, the merciless Indian Savages, whose known rule of warfare, is an undistinguished destruction of all ages, sexes and conditions. ";
  drawDeclaration(2050);
  fun(100);
  scrolltext = "      In every stage of these Oppressions We have Petitioned for Redress in the most humble terms: Our repeated Petitions have been answered only by repeated injury. A Prince whose character is thus marked by every act which may define a Tyrant, is unfit to be the ruler of a free people. Nor have We been wanting in attentions to our Brittish brethren. We have warned them from time to time of attempts by their legislature to extend an unwarrantable jurisdiction over us. We have reminded them of the circumstances of our emigration and settlement here. We have appealed to their native justice and magnanimity, and we have conjured them by the ties of our common kindred to disavow these usurpations, which, would inevitably interrupt our connections and correspondence. They too have been deaf to the voice of justice and of consanguinity. We must, therefore, acquiesce in the necessity, which denounces our Separation, and hold them, as we hold the rest of mankind, Enemies in War, in Peace Friends. We, therefore, the Representatives of the united States of America, in General Congress, Assembled, appealing to the Supreme Judge of the world for the rectitude of our intentions, do, in the Name, and by Authority of the good People of these Colonies, solemnly publish and declare, That these United Colonies are, and of Right ought to be Free and Independent States; that they are Absolved from all Allegiance to the British Crown, and that all political connection between them and the State of Great Britain, is and ought to be totally dissolved; and that as Free and Independent States, they have full Power to levy War, conclude Peace, contract Alliances, establish Commerce, and to do all other Acts and Things which Independent States may of right do. And for the support of this Declaration, with a firm reliance on the protection of divine Providence, we mutually pledge to each other our Lives, our Fortunes and our sacred Honor. ";
  drawDeclaration(1950);
  fun(100);
  scrolltext = "      Georgia Button Gwinnett Lyman Hall George Walton North Carolina William Hooper Joseph Hewes John Penn South Carolina Edward Rutledge Thomas Heyward, Jr. Thomas Lynch, Jr. Arthur Middleton Massachusetts John Hancock Maryland Samuel Chase William Paca Thomas Stone Charles Carroll of Carrollton Virginia George Wythe Richard Henry Lee Thomas Jefferson Benjamin Harrison Thomas Nelson, Jr. Francis Lightfoot Lee Carter Braxton Pennsylvania Robert Morris Benjamin Rush Benjamin Franklin John Morton George Clymer James Smith George Taylor James Wilson George Ross Delaware Caesar Rodney George Read Thomas McKean New York William Floyd Philip Livingston Francis Lewis Lewis Morris New Jersey Richard Stockton John Witherspoon Francis Hopkinson John Hart Abraham Clark New Hampshire Josiah Bartlett William Whipple Massachusetts Samuel Adams John Adams Robert Treat Paine Elbridge Gerry Rhode Island Stephen Hopkins William Ellery Connecticut Roger Sherman Samuel Huntington William Williams Oliver Wolcott New Hampshire Matthew Thornton";
  drawDeclaration(1040);
  fun(100);
}